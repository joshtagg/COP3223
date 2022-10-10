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
struct ll_node * deleteAll(struct ll_node * head);
struct ll_node * deleteEnd(struct ll_node * head);
struct ll_node * deleteSpecific(struct ll_node * head, int data);
int search(struct ll_node * head, int data);    //tells deleteSpecific if the number being searched is actually in the list
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

    myList = deleteSpecific(myList, 9);

    printf("\n---\n\n");

    printList(myList);

    myList = deleteAll(myList);

    /*
    if(myList == NULL)
        printf("List deleted!\n");
    */
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

struct ll_node * deleteEnd(struct ll_node * head) {
    struct ll_node *temp, *helper;

    helper = head;

    //if the list is already empty, nothing to do
    if(head == NULL)
        return NULL;

    //if the first node is the only node in the list, delete it
    if(head->next == NULL) {
        free(head); //free function deletes node
        return NULL;
    }

    while(helper->next->next != NULL) {
        helper = helper->next;  //traverse to end of list
    }
    temp = helper->next; //once at end of list, set temp to last node in the list with the NULL pointer as its link
    helper->next = NULL; //remove the link from the actual list
    free(temp); //free memory space of very last node

    return head; //return head of the list
}

struct ll_node * deleteAll(struct ll_node * head) {
    while(head != NULL)     //as long as there is something in the list
        head = deleteEnd(head); //delete from the end of the list
    return NULL;
}

//pre-conditions: search takes in the head of a linked list and the data to search for
//post-conditions: search returns 1 if the data is in the list, 0 otherwise
int search(struct ll_node * head, int data) {
    int flag = 0;   //start by assuming it is not in our list
    struct ll_node *helper = head; //create helper to help traverse the list

    while(helper != NULL) {
        if(helper->data == data)    //if helper->data is equal to the data we're looking for
            flag = 1;
        helper = helper->next;  //traverse to next spot in list
    }

    return flag;
}

struct ll_node * deleteSpecific(struct ll_node * head, int data) {
    struct ll_node *helper = head, *temp; //start helper at the head of the list
    //                                      create a temp pointer to hold the node that will be deleted

    if(head == NULL) //if head is empty, nothing to delete
        return head;

    if(!search(head, data)) //if information is not found, return list unchanged
        return head;

    //check front
    if(head->data == data) {
        head = head->next; //advance the head of the list
        free(helper); //free the first node
        return head; //return the list
    }

    //traverse the list
    while(helper->next != NULL) { //as long as we aren't at the end of the list
        //if the next nodes data matches our data
        if(helper->next->data == data) { //skips over the first node (already checked)
            temp = helper->next;
            helper->next = helper->next->next; //helper points to spot after the one we are getting rid of, temp->next would also work here instead of helper->next
            free(temp);
            return head;
        }
        helper = helper->next; //sets helper to last node??(for next loop)
    }

    //delete end
    //if the last node has our data in it
    if(helper->data == data)
        head = deleteEnd(head); //delete the very last node

    return head;
}











