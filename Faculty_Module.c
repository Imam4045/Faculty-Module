#include "Faculty_Module.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* GetDesignationString(enum Designation designation) {
    switch (designation) {
        case 1:
            return "LECTURER";
        case 2:
            return "SENIOR LECTURER";
        case 3:
            return "ASSOCIATE PROFESSOR";
        case 4:
            return "ASSISTANT PROFESSOR";
        case 5:
            return "PROFESSOR";
        default:
            return "UNKNOWN";
    }
}
char* GetDepartmentString(enum Department department) {
    switch (department) {
        case 10:
            return "CSE";
        case 11:
            return "EEE";
        case 12:
            return "ECE";
        case 13:
            return "GEB";
        case 14:
            return "PHARM";
        case 15:
            return "CE";
        case 16:
            return "MPS";
        case 20:
            return "ENGLISH";
        case 21:
            return "LAW";
        case 22:
            return "SOCIAL RELATIONS";
        case 23:
            return "INFORMATION STUDIES";
        case 24:
            return "SOCIOLOGY";
        case 30:
            return "BA";
        case 31:
            return "ECONOMICS";
        default:
            return "UNKNOWN";
    }
}

struct Faculty_Profile* CreateFaculty(struct Faculty_Profile* head) {

    char* Name = (char*)malloc(sizeof(char));
    char* Initial = (char*)malloc(sizeof(char));
    char* Address = (char*)malloc(sizeof(char));
    char* Phone_number = (char*)malloc(sizeof(char));
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
    printf("Enter Designation (1-5): ");
    scanf("%d", &des);
    printf("Enter Department (10-16, 20-24, 30-31): ");
    scanf("%d", &dep);
    getchar(); // To consume the newline character left by scanf

    struct Faculty_Profile* newNode = (struct Faculty_Profile*)malloc(sizeof(struct Faculty_Profile));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->name = Name;
    newNode->initial = Initial;
    newNode->address = Address;
    newNode->phone_number = Phone_number;
    newNode->designation = (enum Designation)des;
    newNode->department = (enum Department)dep;
    newNode->next = NULL;

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
    struct Faculty_Profile* newp = (struct Faculty_Profile*)malloc(sizeof(struct Faculty_Profile));
    if (newp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int des, dep;
    printf("Enter Designation (1-5): ");
    scanf("%d", &des);
    printf("Enter Department (10-16, 20-24, 30-31): ");
    scanf("%d", &dep);

    newp->name = Name;
    newp->initial = Initial;
    newp->address = Address;
    newp->phone_number = Phone_number;
    newp->designation = (enum Designation)des;
    newp->department = (enum Department)dep;
    newp->next = NULL;

    if (position < 1) {
        printf("\nInvalid position.\n");
        return head;
    }

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
    struct Faculty_Profile* temp = head;
    struct Faculty_Profile* temp2 = NULL;
    struct Faculty_Profile* current = head;

    if (head == NULL) {
        printf("List is empty");
    }
    else if (Position == 1) {
        head = head->next;
        free(temp);
        temp = NULL;
        return head;
    }
    else {
        while (Position > 1 && current != NULL) {
            temp2 = current;
            current = current->next;
            Position--;
        }
        temp2->next = current->next;
        free(current);
        current = NULL;
        return head;
    }
}

struct Faculty_Profile* SearchFaculty_By_Initial(struct Faculty_Profile* head, char* initial) {
    struct Faculty_Profile* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->initial, initial) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL; // Faculty not found
}

void Modify_Faculty(struct Faculty_Profile* faculty) {
    if (faculty == NULL) {
        printf("Faculty not found.\n");
        return;
    }

    char* newName = (char*)malloc(sizeof(char));
    char* newInitial = (char*)malloc(sizeof(char));
    char* newAddress = (char*)malloc(sizeof(char));
    char* newPhoneNumber = (char*)malloc(sizeof(char));
    int newDesignation, newDepartment;


    printf("Enter Name: ");
    newName = CharacterStringInput(newName);
    printf("Enter Initial: ");
    newInitial = CharacterStringInput(newInitial);
    printf("Enter Address: ");
    newAddress = CharacterStringInput(newAddress);
    printf("Enter PhoneNumber: ");
    newPhoneNumber = CharacterStringInput(newPhoneNumber);
    printf("Enter Designation (1-5): ");
    scanf("%d", &newDesignation);
    printf("Enter Department (10-16, 20-24, 30-31): ");
    scanf("%d", &newDepartment);
    getchar(); // To consume the newline character left by scanf


    // Assign new data
    faculty->name = newName;
    faculty->initial = newInitial;
    faculty->address = newAddress;
    faculty->phone_number = newPhoneNumber;
    faculty->designation = (enum Designation)newDesignation;
    faculty->department = (enum Department)newDepartment;

    printf("Faculty information updated.\n\n");
}

void Faculty_ListDisplay(struct Faculty_Profile* head) {
    struct Faculty_Profile* temp = head;
    if (head == NULL) {
        printf("\n\nThere is no list to show the data.\n");
    }
    else {
        printf("Display List for Faculties: \n");
        printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("%-45s %-25s %-25s %-25s %-30s %-30s\n", "Name", "Initial", "Address", "PhoneNumber", "Designation", "Department");
        printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        while (temp != NULL) {
            printf("%-45s %-25s %-25s %-25s %-30s %-30s\n", temp->name, temp->initial, temp->address, temp->phone_number, GetDesignationString(temp->designation), GetDepartmentString(temp->department));
            temp = temp->next;
        }
    }
}

char* CharacterStringInput(char* c) {
    /*if (c == NULL) {
        c = (char*)malloc(sizeof(char));
    }*/
    int i, n;
    *c = '\0';
    for (i = 0; (n = getchar()) != '\n'; i++) {
        c = realloc(c, (i + 2));
        *(c + i) = (char)n;
        *(c + i + 1) = '\0';
    }
    return c;
}
