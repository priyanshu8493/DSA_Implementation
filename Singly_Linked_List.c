/* 
Complete End to End implementation of Singly Linked Lists with every operation implemented by means of an user defined function
*/



#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*temp;


// function to create a singly linked list dynamically

struct node * create(){

    int choice = 1;
    struct node *head=NULL,  *new_node;

    while(choice){


    

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;
    printf("Node Created ! Enter data - \n"); scanf("%d", &new_node->data);

    if (head==NULL){
        head = temp = new_node;

    }
    else{
        temp->next = new_node;
        temp = new_node;
    }
    printf("\nNode added to the list\n");

    printf("\nAdd more nodes? (0/1)\n"); scanf("%d", &choice);
    }

    return head;

}


//function to traverse and print the list

void trav( struct node *head ){

    temp = head;
    printf("\nThe Linked List is - \n");
    while(temp!=NULL){

        printf("\n%d", temp->data);
        temp = temp->next;

    }
    printf("\n");
}



//fucntion to insert a node at begining
struct node *ins_at_beg(struct node *head ){

    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nThe node has been created to insert ! Enter data - \n"); scanf("%d",&new_node->data);

    new_node->next = head;
    head = new_node;

    return head;

}

// insertion at end

struct node *ins_at_end(struct node*head){
    temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    // temp now points to the last node
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nNew node to insert has been created, enter data - \n");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    temp->next = new_node;
    return head;

}

// insertion at given pos

struct node * ins_at_pos(struct node *head){
    int pos;
    printf("Enter the position where node is to be inserted - \n");
    scanf("%d", &pos);

    struct node *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nNew node created ! Enter data -\n"); scanf("%d", &new_node->data);

    temp = head;

    if(pos==1){
        head = ins_at_beg(head);   // invokes the in_at_beg() function; so will have to input the parameter datas twice, once for pos() and for beg()
    }
    else{

    for(int i = 1; i<=(pos-2); i++){
        temp = temp->next;

    }

    new_node->next = temp->next;
    temp->next = new_node;
    
    }

    return head;
}


// deletion at beg

struct node * del_at_beg(struct node* head){
    temp = head;
    head = head->next;
    free(temp);
    printf("\nThe first node has been deleted !\n");

    
    return head;
}

// deletion at the end 


struct node * del_at_end(struct node * head){
    temp = head;
    struct node *temp2;

    while(temp->next->next!=NULL){
        temp = temp->next;

    }
    temp2 = temp->next;  // pointer to the last node


    temp->next = NULL;
    free(temp2);

    printf("\nThe last node has been deleted !\n");

    return head;

}


// deletion at a given pos


struct node * del_at_pos(struct node* head){
    int pos;
    printf("\nEnter the pos of the node you want to delete! \n");
    scanf("%d", &pos);

    if( pos == 1 ){
        head = del_at_beg(head);
    }

    else{

        temp = head;
        for(int i =1; i<=pos-2; i++){
            temp = temp->next;
        }
        // temp now points to the node before the node to be deleted

        struct node *temp2;
        temp2 = temp->next;

        temp->next = temp2->next;
        free(temp2);
    }
    
    printf("\nThe desired node has been deleted from the face of this existence\n");

    return head;
}


// Reversal

struct node * prev(struct node* head){
    struct node *prev = NULL;
    struct node *next;
    temp = head;


    while( next != NULL ){

        next = temp->next;
        temp->next = prev;

        prev = temp;
        temp = next;
    }

    head = prev;
    printf("\nThe linked list has been reversed \n");
    return head;

}



int main(){

    struct node *head;

    head = create();
    trav(head);
    head = prev(head);
    trav(head);
    return 0;
}