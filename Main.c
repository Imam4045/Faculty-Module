#include "Faculty_Module.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct Faculty_Profile* Head = NULL;
    int choice, Position;
    char* Name, *Initial, *Address, *Phone_number;

    while (1) {
        printf("\n****Faculty Menu****\n");
        printf("0. Exit the programme\n");
        printf("1. Create Faculty\n");
        printf("2. Insert Faculty At Any Position\n");
        printf("3. Delete Faculty At Any Position\n");
        printf("4. Search Faculty\n");
        printf("5. Modify Faculty\n");
        printf("6. Display List for Faculty\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting program.\n");
                exit(0);
            case 1:
                Head = CreateFaculty(Head);
                break;

            case 2:
                if (Head == NULL) {
                    printf("\nThe list is empty. Use option 1 to create the list first.\n");
                    break;
                }
                Name = (char*)malloc(sizeof(char));
                Initial = (char*)malloc(sizeof(char));
                Address = (char*)malloc(sizeof(char));
                Phone_number = (char*)malloc(sizeof(char));
                printf("Enter the position: ");
                scanf("%d", &Position);
                printf("Enter Name: ");
                getchar(); // Clear the newline character
                Name = CharacterStringInput(Name);
                printf("Enter Initial: ");
                Initial = CharacterStringInput(Initial);
                printf("Enter Address: ");
                Address = CharacterStringInput(Address);
                printf("Enter PhoneNumber: ");
                Phone_number = CharacterStringInput(Phone_number);
                Head = InsertFaculty_At_AnyPosition(Head, Name, Initial, Address, Phone_number, Position);
                printf("\nFaculty has been inserted.\n");
                break;
            case 3:
                if (Head == NULL) {
                    printf("\nThe list is empty. Use option 1 to create the list first.\n");
                    break;
                }
                printf("Enter a position you want to delete a faculty: ");
                scanf("%d", &Position);
                Head = DeleteFaculty_At_AnyPosition(Head, Position);
                printf("Faculty has been deleted.\n");
                break;

            case 4:
                if (Head == NULL) {
                    printf("\nThe list is empty. Use option 1 to create the list first.\n");
                    break;
                }
                Initial = (char*)malloc(sizeof(char));
                printf("Enter Initial of the faculty to search: ");
                getchar(); // Clear the newline character
                Initial = CharacterStringInput(Initial);
                struct Faculty_Profile* found = SearchFaculty_By_Initial(Head, Initial);
                if (found != NULL) {
                    printf("*****Searched Faculty Information*****\n");
                    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("%-45s %-25s %-25s %-25s %-30s %-30s\n", "Name", "Initial", "Address", "PhoneNumber", "Designation", "Department");
                    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("%-45s %-25s %-25s %-25s %-30s %-30s\n", found->name, found->initial, found->address, found->phone_number, GetDesignationString(found->designation), GetDepartmentString(found->department));
                } else {
                    printf("\nFaculty not found\n");
                }
                free(Initial);
                break;

            case 5:
                if (Head == NULL) {
                    printf("\nThe list is empty. Use option 1 to create the list first.\n");
                    break;
                }
                Initial = (char*)malloc(sizeof(char));
                printf("Enter Initial of the faculty to modify: ");
                getchar();
                Initial = CharacterStringInput(Initial);
                struct Faculty_Profile* facultyToModify = SearchFaculty_By_Initial(Head, Initial);
                if (facultyToModify != NULL) {
                    Modify_Faculty(facultyToModify);
                }
                else {
                    printf("\nFaculty not found\n");
                }
                free(Initial);
                break;

            case 6:
                Faculty_ListDisplay(Head);
                break;

            default:
                printf("Invalid choice. Please enter a number between 0 to 6.\n");
                break;
        }
    }
    return 0;
}
