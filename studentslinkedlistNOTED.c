/*Sarah Angell
 *This program demonstrates linked lists
 *A list of students will be read from a file and sorted
 */

//included libraries
#include <stdio.h>
#include <string.h>

//constants
#define MAX 20
#define NUMSTUDENTS 5

// Structure for student records list
// The data portion is formed by two strings and one integer
// The link portion is a pointer of the same type as the structure
struct record {
    char fname[MAX];
    char lname[MAX];
    int PID;
    struct record * next;
};

// Function prototypes to operate on the linked list
// We will be able to add in order, print the list, and delete the list
int studentcmp(struct record studentA, struct record studentB);
struct record * getStudents(struct record * head);
struct record * insert(struct record * head, struct record * newNode);
void printStudents(struct record * head);
struct record * deleteEnd(struct record * head);
struct record * deleteAll(struct record * head);

int main(void) {
    // Create an empty list to start with
    struct record * studentList = NULL;

    // Use the getStudents function to read information into the list
    studentList = getStudents(studentList);

    // Print the list
    printStudents(studentList);

    // Delete the list
    studentList = deleteAll(studentList);

    // If the list is deleted, we can exit the program with no errors
    if(studentList == NULL) {
        printf("List deleted.  Exiting program...\n");
        return 0;
    }
    else
        return 1;
}

// Compares two students of type struct record
// Returns -1 if studentA should come first in the roster
// Returns 1 if studentB should come first
// Returns 0 if the two records are the same
int studentcmp(struct record studentA, struct record studentB) {
    if (strcmp(studentA.lname, studentB.lname) < 0)
        return -1;
    else if (strcmp(studentA.lname, studentB.lname) > 0)
        return 1;
    else {
        if (strcmp(studentA.fname, studentB.fname) < 0)
            return -1;
        else if (strcmp(studentA.fname, studentB.fname) > 0)
            return 1;
        else {
            if (studentA.PID < studentB.PID)
                return -1;
            else if (studentA.PID > studentB.PID)
                return 1;
            else
                return 0;
        }
    }
}

// Read information from a file
// Create space for a new student record
// Call insert to add the student to the list
struct record * getStudents(struct record * head) {
    // Open the file of student records
    FILE * ifp = fopen("student.txt", "r");
    int i;
    struct record * temp;

    // For each student...
    for(i=0; i<NUMSTUDENTS; i++) {
        // Allocate space for them
        temp = (struct record *)malloc(sizeof(struct record));

        // Move information from the file to the new data space
        fscanf(ifp, "%s", temp->lname);
        fscanf(ifp, "%s", temp->fname);
        fscanf(ifp, "%d", &temp->PID);

        // Initialize the link to NULL
        temp->next = NULL;

        // Call insert to add the new student record to the list
        head = insert(head, temp);
    }

    // Return the beginning of the list to main
    return head;
}

// Perform an insert in order: adding newNode to head
struct record * insert(struct record * head, struct record * newNode) {
    // Create a helper pointer to start at the beginning of the list
    struct record * helper = head;

    // Check list is empty
    if (head == NULL)
        return newNode;

    // Check front of list
    if (studentcmp( *(newNode), *(head)) < 0) {
        newNode->next = head;
        return newNode;
    }

    // Check middle
    while(helper->next != NULL) {
        // Look for the successor to newNode
        // It will be the first node that newNode comes in front of
        // alphabetically based on studentcmp
        // helper will be the predecessor, helper->next will be the successor
        if (studentcmp(*(newNode), *(helper->next)) <=0) {
            // newNode should point to the successor
            newNode->next = helper->next;
            // Predecessor should point to newNode
            helper->next = newNode;
            // Return the head of the list
            return head;
        }
        //Advance helper until the correct location is found or
        // until the end of the list is reached
        helper = helper->next;
    }

    // Add to end
    helper->next = newNode;

    // Return the head of the list
    return head;
}

// Print each record in the list
void printStudents(struct record * head) {
    // Create a helper pointer to preserve the head of the list
    struct record * helper = head;

    // As long as helper is not NULL, print the contents of helper
    while(helper != NULL) {
        printf("%s %s: %d\n\n", helper->lname, helper->fname, helper->PID);
        helper = helper->next;
    }

    return;
}

// Delete the last node
struct record * deleteEnd(struct record * head) {
    // Create a helper and a temp pointer
    struct record * helper = head, *temp;

    // If the list is empty, then there is nothing to delete
    if (head == NULL)
        return head;

    // If there is only one node in the list, delete that node
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Navigate to the second to last node
    while (helper->next->next != NULL)
        helper = helper->next;

    // Set temp equal to the last node
    temp = helper->next;
    // Make the second to last node the last node
    helper->next = NULL;
    // Free the space for temp
    free(temp);

    return head;
}

// Deletes all the nodes in the list using deleteEnd
struct record * deleteAll(struct record * head) {
    while(head != NULL)
        head = deleteEnd(head);
    return NULL;
}
