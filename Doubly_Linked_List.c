// Doubly Linked Lists implementation with its operations via user defined functions
#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
    struct node *prev;
}*temp,*head,*new_node;


struct node * create(){
    head = temp = NULL;
    int choice =1;
    while(choice){

        new_node = (struct node *)malloc(sizeof(struct node));

        printf("\nA new node has been created, Enter data - \n");
        scanf("%d", &new_node->data);
        new_node->next = NULL;

        if ( head == NULL ) {

            new_node->next = NULL;
            head = new_node;
            temp = new_node;

        }

        else{

            new_node->prev = temp;
            temp->next = new_node;
            temp = new_node;

        }

        printf("\nAdd more nodes? (0/1)\n");
        scanf("%d",&choice);

    }
    return head;
}


// traversal function 

void trav(struct node * head){
    int ch;
    printf("\nForward or Reverse? (0/1)\n");
    scanf("%d",&ch);

    printf("\nThe Linked list is - \n");

    if(ch==0){
        temp = head;
        while (temp != NULL){
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        while(temp!=NULL){
            printf("%d\n", temp->data);
            
            temp = temp->prev;
        }
    }

}

// insertion at begining 

struct node * ins_at_beg(struct node * head){
    new_node = (struct node * )malloc(sizeof(struct node));
    printf("\nNew node has beeen created, Enter data - \n");
    scanf("%d", &new_node->data);
    new_node->next = head;
    head->prev = new_node;
    new_node->prev = NULL;
    head = new_node;

    return head;

}

// insertion at end

struct node * ins_at_end(struct node * head){
    temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    new_node= (struct node*)malloc(sizeof(struct node));
    printf("\nNew node has been created, Enter data - \n");
    scanf("%d", &new_node->data);
    new_node->prev = temp;
    new_node->next = NULL;
    temp->next = new_node;
    printf("\nNew node inserted at the end\n");

    return head;
}

// insertion at given pos

struct node * ins_at_pos(struct node * head){
    int pos;
    printf("\nEnter the pos where you want ot enter the new node- \n");
    scanf("%d", &pos);

    temp = head;

    if(pos==1){
        head = ins_at_beg(head);
    }
    else{

        for(int i =1; i<=(pos-2); i++){
            temp = temp->next;
        }

        //now temp points to the node after which new_node is to be inserted
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter data for the new node-\n");
        scanf("%d",&new_node->data);

        new_node->prev = temp;
        new_node->next = temp->next->next;
        temp->next = new_node;
        new_node->next->prev = new_node;

    }
    printf("\nNode inserted at desired pos\n");

    return head;
}
// deletion at begining

struct node * del_at_beg(struct node* head){
    temp = head;
    head->next->prev = NULL;
    head = head->next;
    free(temp);
    printf("\nThe first node has been deletd from the face of existence \n");
    return head;
}

// deletion at end

struct node * del_at_end(struct node* head){

    struct node * temp2;
    temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    temp2 = temp->next;
    temp->next = NULL;
    free(temp2);

    printf("\nThe last node has been deletd\n");

    return head;

}

//deletion at a given position

struct node * del_at_pos(struct node * head){
    int pos;
    printf("\nEnter the position - \n");
    scanf("%d", &pos);

    if ( pos==1 ){
        head = del_at_beg(head);
    }
    else{
        temp = head;
        for ( int i = 0; i<(pos-2); i++){
            temp = temp->next;
        }
        
        struct node * temp2;
        temp2 = temp->next;      // GETTING SEGMENTATION ERROR WHEN DELETING LAST NODE; DEGUG IT

        temp->next = temp2->next;
        temp2->next->prev = temp;
        free(temp2);

        printf("\nDesired node has been deleted \n");
    }
    return head;
    
}


// reversal function

struct node * rev(struct node * head){     //  !!!! works like a charm boi !!!!
    struct node * prev;
    struct node * next;
    temp = head;
    prev = NULL;
    next = temp;

    while( next != NULL ){
        next = temp->next;
        temp->next = prev;
        temp->prev = next;

        prev = temp;
        temp = next;

    }
    head = prev;
    return head;
}


int main(){

    head = create();
    trav(head);
    head = rev(head);
    trav(head);


    return 0;
}