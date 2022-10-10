//Sarah Angell
//This program demonstrates nested structures
//and pointers to structures by creating a farm

#include <stdio.h>

#define MAX 20
#define MAXANIMALS 100

typedef struct {
    char name[MAX];
    char sound[MAX];
}animal;

typedef struct {
    animal farmResidents[MAXANIMALS];
    int size;
}farm;

void addAnimal(farm * myFarm);
void print(farm myFarm);
void menu();

int main() {
    farm myFarm;
    int ans;

    myFarm.size = 0;

    menu()
    scanf("%d", &ans);

    while(and != 3) {
        if(ans == 1)
            addAnimal(&myFarm);
        else if(ans == 2)
            print(myFarm);
        else if(ans == 3)
            ;
        else
            printf("Sorry that was not a valid option.\n");

        menu();
        scanf("%d", &ans);
    }

    return 1;
}

void menu() {
    printf("What would you like to do?\n");
    printf("\t1 - Add Animal\n");
    printf("\t2 - See all animals\n");
    printf("\t3 - Quit\n");
    return;
}

void addAnimal(farm * myFarm) {
    animal newAnimal;

    //if( (*myFarm).size >= MAXANIMALS )
    if(myFarm->size >= MAXANIMALS) {
        printf("Sorry, the farm is full!\n");
        return;
    }

    printf("What animal are you adding to the farm?\n");
    scanf("%s", newAnimal.name);

    printf("What sound does it make?\n");
    scanf("%s", newAnimal.sound);

    myFarm->farmResidents[myFarm->size] = newAnimal;
    myFarm->size++;

    return;
}

void print(farm myFarm) {
    int i;

    for(i = 0; i < myFarm.size; i++) //not a pointer in this function so use normal syntax
        printf("The %s goes %s!\n", myFarm.farmResidents[i].name, myFarm.farmResidents[i].sound);

    return;
}







