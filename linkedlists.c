//Sarah Angell
//This program demonstrates a linked list

#include <stdio.h>

struct ll_node {
    int data;
    struct ll_node * next;
};

struct ll_node * addFront(struct ll_node * head, int data);
struct ll_node * addBack(struct ll_node * head, int data);
struct ll_node * addInOrder(struct ll_node * head, int data);
void printList(struct ll_node * head);

int main() {
    struct ll_node * myList = NULL;
    int num = 0;

    printf("Enter integer values to be stored:\n");
    printf("End with a -1.\n");
    scanf("%d", &num);

    while(num != -1) {
        myList = addInOrder(myList, num);

        scanf("%d", &num);
    }

    printf("\n---\n\n");

    printList(myList);

    return 0;
}

struct ll_node * addFront(struct ll_node * head, int data) {
    struct ll_node * temp = (struct ll_node *)malloc(sizeof(struct ll_node));

    temp->data = data;

    temp->next = head;

    return temp;
}

struct ll_node * addBack(struct ll_node * head, int data) {
    //helper is used to traverse the list
    struct ll_node *temp, *helper;

    //create the new node
    temp = (struct ll_node *)malloc(sizeof(struct ll_node));    //allocate space for new node that is the size of struct ll_node which contains an integer and a pointer
                                                                //cast that to type struct 11_node (hence the (struct ll_node* at beginning)
    temp->data = data; //set the data section from the parent function
    temp->next = NULL; //set linked section to null since this will be the new end of the list

    //set helper to head of list
    helper = head;

    //if list is currently empty the new node is the only node in the list
    if(helper == NULL)
        return temp;
    //otherwise, traverse to end of the list
    while(helper->next != NULL) //finds null pointer at end of list and changes it to the new node that we created
        helper = helper->next;

    helper->next = temp;

    return head;
}

struct ll_node * addInOrder(struct ll_node * head, int data) {
    struct ll_node * temp, *helper;

    //create node
    temp = (struct ll_node *)malloc(sizeof(struct ll_node));
    temp->data = data;
    temp->next = NULL;

    //check for empty (if the list is empty)
    if(head == NULL)
        return temp;

    //check for beginning of list
    if(temp->data < head->data) {
        temp->next = head;
        return temp;
    }

    //traverse list
    helper = head;

    while(helper->next != NULL) {
        if(temp->data < helper->next->data) {
            temp->next = helper->next;
            helper->next = temp;
            return head;
        }
        helper = helper->next;
    }

    //add to end of list
    helper->next = temp;

    //return head of list
    return head;
}


void printList(struct ll_node * head) {
    struct ll_node * helper = head;

    while(helper != NULL) {
        printf("%d\t", helper->data);
        helper = helper->next;
    }

    printf("\n");

    return;
}
