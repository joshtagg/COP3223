#include <stdio.h>

#define MAXLETTERS 20
#define MAXROOMS 10

//typedef reduces struct room to room
typedef struct {
    char name[MAXLETTERS];
    int number;
    int occupants;
} room;

//Hotel is an array of rooms
int menu();
void checkin(room * hotel);
void checkout(room * hotel);
void print(room * hotel);
void search(room * hotel);

int main() {
    room hotel[MAXROOMS];
    int i, choice;

    for(i=0; i<MAXROOMS; i++) {
        hotel[i].number = i+1;
        hotel[i].occupants = 0;
    }


    choice = menu();

    while (choice != 5) {
        switch(choice) {
            case 1:
                checkin(hotel);
                break;
            case 2:
                checkout(hotel);
                break;
            case 3:
                print(hotel);
                break;
            case 4:
                search(hotel);
                break;
            case 5:
                break;
            default:
                printf("Sorry, that was an invalid option.\n");
                break;
        }

        choice = menu();
    }

    return 0;
}

int menu() {
    int option;
    printf("Select one of the following:\n");
    printf("1 - Check In to the hotel\n");
    printf("2 - Check Out of the hotel\n");
    printf("3 - Print the occupants of the hotel\n");
    printf("4 - Search for a visitor to the hotel\n");
    printf("5 - Quit\n");
    scanf("%d", &option);
    return option;
}

void checkin(room * hotel) {
    char name[MAXLETTERS];
    int people, i;

    printf("What is the name of the reservation?\n");
    scanf("%s", name);

    printf("How many people will be checking in?\n");
    scanf("%d", &people);

    for(i = 0; i < MAXROOMS; i++)
        if(hotel[i].occupants == 0)
            break;

    if(i >= MAXROOMS)
        printf("Sorry, no room was found for %s.\n", name);
    else {
        printf("%s was checked in to room %d.\n", name, i+1);
        strcpy(hotel[i].name, name);
        hotel[i].occupants = people;
    }

    printf("\n");

    return;
}

void checkout(room * hotel){
    char name[MAXLETTERS];
    int i, room, flag = 0;

    printf("Who is checking out?\n");
    scanf("%s", name);

    for(i = 0; i < MAXROOMS; i++)
        if(strcmp(hotel[i].name, name) == 0 && hotel[i].occupants != 0) {
            room = i;
            flag = 1;
        }
    if(flag == 0)
        printf("Sorry, there is no occupant named %s.\n", name);
    else {
        hotel[room].occupants = 0;
        printf("%s was checked out of room %d.\n", name, room+1);
    }
    return;
}

void print(room * hotel) {
    int i;

    printf("Room Number\tName\tNumber of Occupants\n");

    for(i = 0; i < MAXROOMS; i++)
        if(hotel[i].occupants != 0)
            printf("%d\t%s\t%d\n", hotel[i].number, hotel[i].name, hotel[i].occupants);

    printf("\n");

    return;
}

void search(room * hotel){
    char name[MAXLETTERS];
    int i, flag = -1;

    printf("Which guest are you searching for?\n");
    scanf("%s", name);

    for(i = 0; i < MAXROOMS; i++)
        if(strcmp(hotel[i].name, name) == 0 && hotel[i].occupants != 0)
            flag = i;

    if(flag == -1)
        printf("Sorry, %s was not found in the hotel.\n", name);
    else
        printf("%s is staying in room %d.\n", name, flag+1);

    return;
}








