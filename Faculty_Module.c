#include "Faculty_Module.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const char* GetDesignationString(enum Designation designation) {
    switch (designation) {
        case LECTURER:            return "LECTURER";
        case SENIOR_LECTURER:     return "SENIOR LECTURER";
        case ASSOCIATE_PROFESSOR: return "ASSOCIATE PROFESSOR";
        case ASSISTANT_PROFESSOR: return "ASSISTANT PROFESSOR";
        case PROFESSOR:           return "PROFESSOR";
        default:                  return "UNKNOWN";
    }
}

const char* GetDepartmentString(enum Department department) {
    switch (department) {
        case CSE:                return "CSE";
        case EEE:                return "EEE";
        case ECE:                return "ECE";
        case GEB:                return "GEB";
        case PHARM:              return "PHARM";
        case CE:                 return "CE";
        case MPS:                return "MPS";
        case ENGLISH:            return "ENGLISH";
        case LAW:                return "LAW";
        case SOCIAL_RELATIONS:   return "SOCIAL RELATIONS";
        case INFORMATION_STUDIES:return "INFORMATION STUDIES";
        case SOCIOLOGY:          return "SOCIOLOGY";
        case BA:                 return "BA";
        case ECONOMICS:          return "ECONOMICS";
        default:                 return "UNKNOWN";
    }
}

int IsValidDesignation(int des) {
    return (des >= 1 && des <= 5);
}

int IsValidDepartment(int dep) {
    return (dep == 10 || dep == 11 || dep == 12 || dep == 13 ||
            dep == 14 || dep == 15 || dep == 16 ||
            dep == 20 || dep == 21 || dep == 22 || dep == 23 || dep == 24 ||
            dep == 30 || dep == 31);
}

struct Faculty_Profile* CreateFaculty(struct Faculty_Profile* head) {

    char* Name         = (char*)malloc(sizeof(char));
    char* Initial      = (char*)malloc(sizeof(char));
    char* Address      = (char*)malloc(sizeof(char));
    char* Phone_number = (char*)malloc(sizeof(char));

    if (!Name || !Initial || !Address || !Phone_number) {  
        printf("Memory allocation failed.\n");
        free(Name); free(Initial); free(Address); free(Phone_number);
        return head;
    }

    int des, dep;

    printf("\nEnter Name: ");
    getchar();
    Name = CharacterStringInput(Name);
    printf("Enter Initial: ");
    Initial = CharacterStringInput(Initial);
    printf("Enter Address: ");
    Address = CharacterStringInput(Address);
    printf("Enter PhoneNumber: ");
    Phone_number = CharacterStringInput(Phone_number);

    do {
        printf("Enter Designation (1=Lecturer, 2=Senior Lecturer, 3=Assoc. Prof, 4=Asst. Prof, 5=Professor): ");
        scanf("%d", &des);
        if (!IsValidDesignation(des))
            printf("  Invalid designation. Please enter a value between 1 and 5.\n");
    } while (!IsValidDesignation(des));

    do {
        printf("Enter Department (10-16, 20-24, 30-31): ");
        scanf("%d", &dep);
        if (!IsValidDepartment(dep))
            printf("  Invalid department. Please enter a valid department code.\n");
    } while (!IsValidDepartment(dep));

    getchar(); // consume newline left by scanf

    struct Faculty_Profile* newNode = (struct Faculty_Profile*)malloc(sizeof(struct Faculty_Profile));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        free(Name); free(Initial); free(Address); free(Phone_number);
        return head;                        
    }
    newNode->name         = Name;
    newNode->initial      = Initial;
    newNode->address      = Address;
    newNode->phone_number = Phone_number;
    newNode->designation  = (enum Designation)des;
    newNode->department   = (enum Department)dep;
    newNode->next         = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Faculty_Profile* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("New Faculty \"%s\" added.\n", Name);
    return head;
}

struct Faculty_Profile* InsertFaculty_At_AnyPosition(struct Faculty_Profile* head, char* Name, char* Initial, char* Address, char* Phone_number, int position) {

    if (position < 1) {
        printf("\nInvalid position.\n");
        return head;
    }

    struct Faculty_Profile* newp = (struct Faculty_Profile*)malloc(sizeof(struct Faculty_Profile));
    if (newp == NULL) {
        printf("Memory allocation failed.\n");
        return head;                       
    }

    int des, dep;

    do {
        printf("Enter Designation (1-5): ");
        scanf("%d", &des);
        if (!IsValidDesignation(des))
            printf("  Invalid designation. Please enter a value between 1 and 5.\n");
    } while (!IsValidDesignation(des));

    do {
        printf("Enter Department (10-16, 20-24, 30-31): ");
        scanf("%d", &dep);
        if (!IsValidDepartment(dep))
            printf("  Invalid department. Please enter a valid department code.\n");
    } while (!IsValidDepartment(dep));

    newp->name         = Name;
    newp->initial      = Initial;
    newp->address      = Address;
    newp->phone_number = Phone_number;
    newp->designation  = (enum Designation)des;
    newp->department   = (enum Department)dep;
    newp->next         = NULL;

    if (position == 1) {
        newp->next = head;
        head = newp;
        return head;
    }

    struct Faculty_Profile* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp->next == NULL) {
            printf("\nPosition out of range. Node will be inserted at the end of the list.\n");
            break;
        }
        temp = temp->next;
    }

    newp->next = temp->next;
    temp->next = newp;
    return head;
}

struct Faculty_Profile* DeleteFaculty_At_AnyPosition(struct Faculty_Profile* head, int Position) {

    if (Position < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return head;
    }

    if (head == NULL) {
        printf("List is empty.\n");
        return head;                          
    }

    struct Faculty_Profile* temp = head;

    if (Position == 1) {
        head = head->next;

        free(temp->name);
        free(temp->initial);
        free(temp->address);
        free(temp->phone_number);
        free(temp);
        return head;
    }

    struct Faculty_Profile* prev = NULL;
    struct Faculty_Profile* current = head;

    for (int i = 1; i < Position; i++) {
        if (current == NULL) {
            printf("Position %d is out of range. List has fewer nodes.\n", Position);
            return head;
        }
        prev    = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Position %d is out of range. List has fewer nodes.\n", Position);
        return head;
    }

    prev->next = current->next;

    free(current->name);
    free(current->initial);
    free(current->address);
    free(current->phone_number);
    free(current);

    return head;
}

struct Faculty_Profile* SearchFaculty_By_Initial(struct Faculty_Profile* head, char* initial) {
    struct Faculty_Profile* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->initial, initial) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void Modify_Faculty(struct Faculty_Profile* faculty) {
    if (faculty == NULL) {
        printf("Faculty not found.\n");
        return;
    }

    char* newName        = (char*)malloc(sizeof(char));
    char* newInitial     = (char*)malloc(sizeof(char));
    char* newAddress     = (char*)malloc(sizeof(char));
    char* newPhoneNumber = (char*)malloc(sizeof(char));

    if (!newName || !newInitial || !newAddress || !newPhoneNumber) {
        printf("Memory allocation failed.\n");
        free(newName); free(newInitial); free(newAddress); free(newPhoneNumber);
        return;
    }

    int newDesignation, newDepartment;

    printf("Enter Name: ");
    newName = CharacterStringInput(newName);
    printf("Enter Initial: ");
    newInitial = CharacterStringInput(newInitial);
    printf("Enter Address: ");
    newAddress = CharacterStringInput(newAddress);
    printf("Enter PhoneNumber: ");
    newPhoneNumber = CharacterStringInput(newPhoneNumber);

    do {
        printf("Enter Designation (1-5): ");
        scanf("%d", &newDesignation);
        if (!IsValidDesignation(newDesignation))
            printf("  Invalid designation. Please enter a value between 1 and 5.\n");
    } while (!IsValidDesignation(newDesignation));

    do {
        printf("Enter Department (10-16, 20-24, 30-31): ");
        scanf("%d", &newDepartment);
        if (!IsValidDepartment(newDepartment))
            printf("  Invalid department. Please enter a valid department code.\n");
    } while (!IsValidDepartment(newDepartment));

    getchar();

    free(faculty->name);
    free(faculty->initial);
    free(faculty->address);
    free(faculty->phone_number);

    faculty->name         = newName;
    faculty->initial      = newInitial;
    faculty->address      = newAddress;
    faculty->phone_number = newPhoneNumber;
    faculty->designation  = (enum Designation)newDesignation;
    faculty->department   = (enum Department)newDepartment;

    printf("Faculty information updated.\n\n");
}

void Faculty_ListDisplay(struct Faculty_Profile* head) {
    if (head == NULL) {
        printf("\n\nThere is no list to show the data.\n");
        return;
    }
    struct Faculty_Profile* temp = head;
    printf("\nDisplay List for Faculties:\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-45s %-25s %-25s %-25s %-30s %-30s\n", "Name", "Initial", "Address", "PhoneNumber", "Designation", "Department");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    while (temp != NULL) {
        printf("%-45s %-25s %-25s %-25s %-30s %-30s\n",
            temp->name,
            temp->initial,
            temp->address,
            temp->phone_number,
            GetDesignationString(temp->designation),
            GetDepartmentString(temp->department));
        temp = temp->next;
    }
}

void FreeList(struct Faculty_Profile* head) {
    struct Faculty_Profile* current = head;
    while (current != NULL) {
        struct Faculty_Profile* next = current->next;
        free(current->name);
        free(current->initial);
        free(current->address);
        free(current->phone_number);
        free(current);
        current = next;
    }
}

char* CharacterStringInput(char* c) {
    int i = 0, n;
    *c = '\0';
    while ((n = getchar()) != '\n' && n != EOF) {
        char* temp = realloc(c, (i + 2));
        if (temp == NULL) {                    
            printf("Memory allocation failed during input.\n");
            free(c);
            return NULL;
        }
        c = temp;
        c[i]     = (char)n;
        c[i + 1] = '\0';
        i++;
    }
    return c;
}
