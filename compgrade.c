//Sarah Angell
//This program demonstrates the use of
//Pass-By-Value functions
//This program calculates a GPA
//based on credit hours and letter grades

//pre-processor directives
#include <stdio.h>

//function prototypes
int comp_grade(char grade);

//main
int main() {
    int total_points = 0, total_hours = 0, c_hours;
    char my_grade, ans = 'y';

    while (ans == 'y' || ans == 'Y') {
        printf("Enter your letter grade.\n");
        scanf(" %c", &my_grade);

        printf("Enter the number of credit hours.\n");
        scanf("%d", &c_hours);

        //when this is read, goes outside main to other function
        //value of my_grade gets passed to other function
        //must be a character in order to go to other function. types have to match up
        total_points += c_hours * comp_grade(my_grade);
        total_hours += c_hours;

        printf("Do you have another grade to enter? (y/n)\n");
        scanf(" %c", &ans);
    }

    //both are integers so make one a double
    printf("Your GPA is %.2lf.\n", (double)total_points / total_hours);


    return 0;
}



//Pre-Condition: grade has to be A, B, C, D, or F
//Post-Condition: An integer value will be returned that
//                corresponds to the letter grade
//                If the grade is invalid, -1 is returned
int comp_grade(char grade) { //grade = my_grade from main, grade takes on the value of my_grade from main due to the function call above (line 27)
    if (grade == 'A')        // it can even accept anything that is a character, hence the "char" before "grade"
        return 4;
        //return command will end the function, go back to main
    else if (grade == 'B')
        return 3;
    else if (grade == 'C')
        return 2;
    else if (grade == 'D')
        return 1;
    else if (grade == 'F')
        return 0;
    else
        return -1;
}

//int comp_grade(char grade)
    //int: what the function returns
    //char: what the function accepts
    //comp_grade: name of function. gets called in main
