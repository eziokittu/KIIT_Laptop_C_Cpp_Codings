#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev; 
    int data; // integer circular doubly linke dlist
    struct node *next;
};

typedef struct node node;

node *head = NULL; // head node 

void CreateNode(){
    node *temp = (node*) malloc (sizeof(node));
    if (temp == NULL){
        printf("\nMemory Heap is full!");
        return;
    }
    printf("\nEnter data for new node : ");
    scanf("%d", &temp->data);
    if (head == NULL){
        head = temp;
        temp->next = temp;
        temp->prev = temp;
    }
    else {
        node *p=head->prev;
        p->next = temp;
        head->prev = temp;
        temp->next = head;
        temp->next = head;
        temp->prev = p;
        p = NULL;
    }
    temp = NULL;
}

void main(){

}