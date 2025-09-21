#ifndef FACULTY_MODULE_H
#define FACULTY_MODULE_H

/* Enumeration to represent different designations of faculty members
 * @Enum Values:
 *  - LECTURER: value 1, represents a Lecturer
 *  - SENIOR_LECTURER: value 2, represents a Senior Lecturer
 *  - ASSOCIATE_PROFESSOR: value 3, represents an Associate Professor
 *  - ASSISTANT_PROFESSOR: value 4, represents an Assistant Professor
 *  - PROFESSOR: value 5, represents a Professor
 */
enum Designation {
    LECTURER = 1,
    SENIOR_LECTURER,
    ASSOCIATE_PROFESSOR,
    ASSISTANT_PROFESSOR,
    PROFESSOR
};

/* Enumeration representing different departments in an institution
 * @Enum Values:
 *  - CSE: value 10, represents Computer Science and Engineering
 *  - EEE: value 11, represents Electrical and Electronic Engineering
 *  - ECE: value 12, represents Electronics and Communication Engineering
 *  - GEB: value 13, represents General Educational Building
 *  - PHARM: value 14, represents Phramacy
 *  - CE: value 15, represnets Civil Engineering
 *  - MPS: value 16, represents Mathematics and Physical Sciences
 *  - ENGLISH: value 20, represents English
 *  - LAW: value 21, represents law
 *  - SOCIAL_RELATIONS: value 22, represents Social Relations
 *  - INFORMATION_STUDIES: value 23, represnets Information Studies
 *  - SOCIOLOGY: value 24, represents Sociology
 *  - BA: value 30, represents Business Administration
 *  - ECONOMICS: value 31, represents Economics
 */
enum Department {
    CSE = 10,
    EEE,
    ECE,
    GEB,
    PHARM,
    CE,
    MPS,
    ENGLISH = 20,
    LAW,
    SOCIAL_RELATIONS,
    INFORMATION_STUDIES,
    SOCIOLOGY,
    BA = 30,
    ECONOMICS
};

// Structure to hold the profile information of a faculty member
struct Faculty_Profile {
    char* name;
    char* initial;
    char* address;
    char* phone_number;
    enum Department department;
    enum Designation designation;
    struct Faculty_Profile* next;
};

/* Function to get the designation string for a given designation enum value
 * @Parameters:
 *  - enum Designation designation: an enum value representing the faculty member's designation
 * Return Type: a pointer to a string representing the designation name, or "UNKNOWN" if the designation is not recognized
 */
char* GetDesignationString(enum Designation designation);

/* Function to get the department name as a string based on the department enum value
 * @Parameters:
 *  - enum Department department: the enum value representing the department
 * Return Type: a pointer to a string representing the department name, or "UNKNOWN" if the department is not recognized
 */
char* GetDepartmentString(enum Department department);

/* Function to create a new faculty
 * @Parameters: struct Faculty_Profile* head: a pointer to the head of the linked list
 * Return Type: updated head of the linked list
 */
struct Faculty_Profile* CreateFaculty(struct Faculty_Profile* head);

/* Function to add a new faculty at any position
 * @Parameters:
 *  - struct Faculty_Profile* head: a pointer to the current head of the linked list
 *  - char* Name: a pointer holding the faculty member's name
 *  - char* Initial: a pointer to a string holding the faculty member's initials
 *  - char* Address: a pointer to a string holding the faculty member's address
 *  - char* Phone_number: a pointer to a string holding the faculty member's phone number
 *  - int position: the position at which to insert a new faculty
 *  Return Type: a pointer to the new head of the linked list
 */
struct Faculty_Profile* InsertFaculty_At_AnyPosition(struct Faculty_Profile* head, char* Name, char* Initial, char* Address, char* Phone_number, int position);

/* Function to delete a node at any position
 * @Parameters:
 *  - struct Faculty_Profile* head: a pointer to the current head of the linked list
 *  - int Position: the position at which to delete a faculty
 *  Return Type: a pointer to the new head of the linked list
 */
struct Faculty_Profile* DeleteFaculty_At_AnyPosition(struct Faculty_Profile* head, int Position);

/* Function to search for a faculty member by their Initial
 * @Parameters:
 *  - struct Faculty_Profile* head: a pointer to the head of the linked list
 *  - char* Initial: a pointer representing the name of the faculty member to search for
 * Return Type: a pointer to the Faculty_Profile node if found, otherwise NULL
*/
struct Faculty_Profile* SearchFaculty_By_Initial(struct Faculty_Profile* head, char* initial);

/* Function to modify the details of a faculty member
 * @Parameters:
 *  - struct Faculty_Profile* faculty: a pointer to the Faculty_Profile node to be modified
 * Return Type: void
 */
void Modify_Faculty(struct Faculty_Profile* faculty);

/* Function to display the details of all faculty members
 * Parameters: struct Faculty_Profile* head: a pointer to the head of the linked list
 * Return Type: void
 */
void Faculty_ListDisplay(struct Faculty_Profile* head);

/* Function to dynamically read a string input from the user and store it in a character array
 * @Parameters:
 *  - char* c: a pointer to a character array where the input string will be stored
 * Return Type: a character pointer
 */
char* CharacterStringInput(char* c);

#endif
