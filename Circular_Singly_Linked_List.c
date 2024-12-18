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


// creating a CLL maintaining both head and tail pointers

struct node * create_tail_head(){

    head = NULL;
    struct node *tail = NULL;

    int choice = 1;

    while(choice){

        new_node= (struct node *)malloc(sizeof(struct node));
        new_node->next = NULL;
        printf("\nA new node has been created ! Enter data - \n");
        scanf("%d", &new_node->data);

        if( head == NULL ){
            head = tail = new_node;
        }
        else{

            tail->next = new_node;
            tail = new_node;

        }

        tail->next = head;
        printf("\nDo you want to add more nodes ? (0/1)\n");
        scanf("%d", &choice);

    }
    return head;
}

//creating CLL maintaining only the tail pointer

struct node * create_tail(){
    struct node * tail = NULL;
    int choice = 1;
    while(choice){

        new_node=(struct node *)malloc(sizeof(struct node));
        printf("\nNew node created, Enter data - \n");
        scanf("%d", &new_node->data);

        if( tail == NULL ){
            tail = new_node;
            tail->next = new_node;
        }
        else{

            new_node->next = tail->next;
            tail->next = new_node;
            tail = new_node;
        }

        printf("\nAdd more nodes ? (0/1)\n");
        scanf("%d", &choice);
    }
    return tail;
}

// function for traversing a CLL ( tail maintained )

void trav_tail(struct node * tail){
    temp = tail->next;

    printf("\nThe CLL is - \n");

    do{
        printf("%d\n", temp->data );
        temp = temp->next;

    }while( temp->next != tail->next->next );



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


// function for inserting at begining ( tail maintained CLL )

struct node * ins_at_beg(struct node * tail ){

    new_node = (struct node * )malloc(sizeof(struct node));
    printf("\nEnter data for new node- \n");
    scanf("%d", & new_node->data);


    new_node->next = tail->next;
    tail->next = new_node;
    printf("\nNode inserted at begining !\n");
    return tail;

}
// function to insert at end ( tail maintained )

struct node * ins_at_end(struct node * tail ){
    new_node = (struct node * )malloc(sizeof(struct node));
    printf("\nNew node has been createed , Enter data -\n");
    scanf("%d", &new_node->data);

    new_node->next = tail->next;
    tail->next = new_node;
    tail = new_node;
    printf("\nNode inserted at the end !\n");

    return tail;

}

// insert at given position
struct node * ins_at_pos(struct node * tail ){
    int pos, i=1;
    printf("\nEnter position - \n"); scanf("%d", &pos);
    if (pos==1){
        tail = ins_at_beg(tail);
    }
    else{

    new_node = (struct node * )malloc(sizeof(struct node));
    printf("\nNew node created, Enter data - \n");
    scanf("%d", &new_node->data);

    temp = tail->next;
    while( i < pos-1 ){
        temp = temp->next;
        i++;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    printf("\nNode inserted at desired position\n");}
    return tail;
    

}

// fucntion to delete first node ( tail maintained )

struct node * del_at_beg(struct node * tail){
    
    temp = tail->next;

    if ( tail == NULL ){
        printf("\nList is empty\n");
    }

    else if ( temp == tail ){
        tail = NULL;
        free(temp);
    }

    else{

        tail->next = temp->next;
        free(temp);
        printf("\nFirst node has been deleted\n");

    }
    return tail;
}






int main(){
    struct node * tail;
    tail = create_tail();
    trav_tail(tail);
    tail = del_at_beg(tail);
    trav_tail(tail);
    return 0;
}