// Singly Circular Linked Lists
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head, *temp, *new_node;

// create function that creates a CLL with desired no of nodes and returns the head to that linked list

struct node * create(){
    head = NULL;
    int choice = 1;

    while(choice){

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;
    printf("\nA new node created ! Enter data - \n");
    scanf("%d", &new_node->data);

    if(head==NULL){
        head = temp = new_node;
    }

    else{
        temp->next = new_node;
        temp = new_node;
    }
    temp->next = head;

    printf("\nAdd more nodes? (0/1) - \n");
    scanf("%d", &choice);


    }
    return head;


}


// function for traversing the singly circular linked list

void trav(struct node* head){
    temp = head;
    printf("\nThe Circular Linked List is - \n");

    do{
        printf("%d\n", temp->data);
        temp = temp->next;
    }while (temp->next != head->next );


    
}


int main(){
    
    head = create();
    trav(head);
    return 0;
}