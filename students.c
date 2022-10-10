//Sarah Angell
//This program demonstrates structures
// A list of students will be read from a file and sorted

#include <stdio.h>
#include <string.h>

#define MAX 20
#define NUMSTUDENTS 5

struct record {
    char fname[MAX];
    char lname[MAX];
    int PID;
};

//function prototypes
void printOne(struct record student); //pass by value, neither pointer nor array
void printAll(struct record * students); //pass by reference function (*),
int studentcmp(struct record studentA, struct record studentB); //pass by value, neither pointer nor array
void swap(struct record * students, int i, int j);
void sort(struct record * students);
//test pointer notation for structs
void swap_PIDS(struct record * sA, struct record * sB);

//main
int main() {
    //<type> <var>;
    //type = struct record
    //var = student
    struct record students[NUMSTUDENTS];
    FILE * ifp = fopen("student.txt", "r");
    int i;

    for(i = 0; i < NUMSTUDENTS; i++) {
        fscanf(ifp, "%s", students[i].lname);
        fscanf(ifp, "%s", students[i].fname);
        fscanf(ifp, "%d", &students[i].PID);
    }

    printAll(students);

    //swap_PIDS(&students[0], &students[1]); //give & reference because spots in arrays aren't passed by
    sort(students);

    printf("\n\n");

    printAll(students);

    fclose(ifp);

    /*
    struct record student1, student2;

    student1.PID = 1234567;
    strcpy(student1.fname, "John");
    strcpy(student1.lname, "Smith");

    //printOne(student1);

    printf("Enter a second student:\n");
    printf("First name:\n");
    scanf("%s", student2.fname);
    printf("Last name:\n");
    scanf("%s", student2.lname);
    printf("PID:\n");
    scanf("%d", &student2.PID);

    if(studentcmp(student1, student2) < 0) {
        printOne(student1);
        printOne(student2);
    }
    else if(studentcmp(student1, student2) > 0) {
        printOne(student2);
        printOne(student1);
    }
    else
        printOne(student2);

    */
    return 0;
}

//functions

//prints one struct record
void printOne(struct record student) {
    printf("%s %s\n\t%d\n", student.lname, student.fname, student.PID);
    return;
}

//wrapper function to call printOne
void printAll(struct record * students) {
    int i;

    for(i = 0; i < NUMSTUDENTS; i++)
        printOne(students[i]);

    return;
}

//swaps the PIDS of two students
//only demonstrates the pointer notation for structures
void swap_PIDS(struct record * sA, struct record * sB) {
    int temp = (*sA).PID;
    sA->PID = sB->PID;
    sB->PID = temp;
}

//Compares two students of type struct record
//Returns -1 if studentA should come first in the roster
//Returns 1 if studentB should come first
//Returns 0 if the two records are the same
int studentcmp(struct record studentA, struct record studentB) {
    if(strcmp(studentA.lname, studentB.lname) < 0)
        return -1;
    else if(strcmp(studentA.lname, studentB.lname) > 0)
        return 1;
    else {
        if(strcmp(studentA.fname, studentB.fname) < 0)
            return -1;
        else if(strcmp(studentA.fname, studentB.fname) > 0)
            return 1;
        else {
            if(studentA.PID < studentB.PID)
                return -1;
            else if(studentA.PID > studentB.PID)
                return 1;
            else
                return 0;
        }
    }
}

void swap(struct record * students, int i, int j) {
    struct record temp = students[i];
    students[i] = students[j];
    students[j] = temp;
    return;
}

void sort(struct record * students) {
    int done = 0, i;

    while(!done) {
        done = 1;
        for(i = 1; i < NUMSTUDENTS; i++) {
            if(studentcmp(students[i-1], students[i]) > 0) {
                swap(students, i-1, i);
                done = 0;
            }
        }
    }
    return;
}










