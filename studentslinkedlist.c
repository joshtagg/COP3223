//Sarah Angell
//This program demonstrates linked lists
//A list of students will be read from a file and sorted

//included libraries
#include <stdio.h>
#include <string.h>

//constants
#define MAX 20
#define NUMSTUDENTS 5

//structure for student records
struct record {
    char fname[MAX];
    char lname[MAX];
    int PID;
    struct record * next; //struct record pointer called next
};

//function prototypes
int studentcmp(struct record studentA, struct record studentB);
struct record * getStudents(struct record * head);
struct record * insert(struct record * head, struct record * newNode);
void printStudents(struct record * head);
struct record * deleteEnd(struct record * head);
struct record * deleteAll(struct record * head);

int main() {
    struct record * studentList = NULL;

    studentList = getStudents(studentList);

    printStudents(studentList);

    studentList = deleteAll(studentList);

    if(studentList == NULL)
        printf("List deleted. Exiting program...\n");

    return 0;
}

//Compares two students of type struct record
//Returns -1 if studentA should come first in the roster
//Returns 1 if studentB should come first
//Returns 0 if the two records are the same
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

//read information from a file
//create space for a new student record
//call insert to add the student to the list
struct record * getStudents(struct record * head) {
    FILE * ifp = fopen("student.txt", "r");
    int i;
    struct record * temp;

    for(i = 0; i < NUMSTUDENTS; i++) {
        temp = (struct record *)malloc(sizeof(struct record));

        fscanf(ifp, "%s", temp->lname);
        fscanf(ifp, "%s", temp->fname);
        fscanf(ifp, "%d", &temp->PID);

        temp->next = NULL;

        head = insert(head,temp);
    }
    return head;
}

//perform an insert in order: adding newNode to head
struct record * insert(struct record * head, struct record * newNode) {
    struct record * helper = head;

    //check list is empty
    if (head == NULL) //if our list is empty
        return newNode;

    //check front of list
    if (studentcmp( *(newNode), *(head)) < 0) { //want to know what newNode and head is pointing at, need to de-reference it
        newNode->next = head;
        return newNode;
    }

    //check middle
    while(helper->next != NULL) {
        if(studentcmp(*(newNode), *(helper->next)) <= 0) { //compare current node with node after helper
            newNode->next = helper->next; //newNode points to successor
            helper->next = newNode;
            return head;
        }
        helper = helper->next;
    }


    //add to end
    helper->next = newNode;

    //return the head of the list
    return head;
}

//print each record in the list
void printStudents(struct record * head) {
    //keep creating helper so pointer doesn't move to the head of the list
    struct record * helper = head;

    while(helper != NULL) {
        printf("%s %s: %d\n\n", helper->lname, helper->fname, helper->PID);
        helper = helper->next;
    }
    return;
}

//delete the last node
struct record * deleteEnd(struct record * head) {
    struct record * helper = head, *temp;

    if(head == NULL)
        return head;

    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    while(helper->next->next != NULL)
        helper = helper->next;

    temp = helper->next;
    helper->next = NULL;
    free(temp);

    return head;
}

//deletes all the nodes in the list using deleteEnd
struct record * deleteAll(struct record * head) {
    while(head != NULL)
        head = deleteEnd(head);
    return NULL;
}
























