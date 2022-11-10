#include <stdio.h>
#include <stdlib.h>

void CreateNode(int _data);

typedef struct{
    int data;
    Node *prev;
    Node *next;
} Node;

// 
Node *head = NULL;
Node *prev = NULL;

void CreateNode(int _data){
    Node *temp;
    temp = (Node*) malloc (sizeof(Node));
    temp->data = _data;
    temp->next = NULL;
    temp->prev = NULL;
    
    if (head==NULL) 
        head = temp;

    else{
        Node *p=head;
        while (p->next !=NULL)
            p=p->next;
        p->next = temp;
        p = NULL;
        temp = NULL;
    }

    if (prev==NULL) 
        prev = temp;

    else{
        Node *p=prev;
        while (p->prev !=NULL)
            p=p->prev;
        p->next = temp;
        p = NULL;
        temp = NULL;
    }
}

// WAP to insert a new node in the beginning of the doubly linked list
void InsertAtBegin(Node* head){
    Node *temp;
    temp = (Node*) malloc (sizeof(Node));
    if (temp==NULL){
        printf("Memory Full ");
        exit(1);
    }
    printf("Enter Data : ");
    scanf("%d", temp->data);
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL){
        head = temp;
    }
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// WAP to delete the first node of double linked list
void DeleteAtBegin(Node* head){
    if (head == NULL){
        printf("The linked list does not exist so no node can be deleted");
        exit(1);
    }
    else if (head->next==NULL){
        free(head);
        head=NULL;
    }
    else {
        Node *p=head;
        head=head->next;
        head->prev=NULL;
        free(p);
        p=NULL;
    }
}

void main(){
    int n;
    printf("How many nodes? ");
    scanf("%d", &n);
    
    for (int i=0; i<n; i++){
        int d;
        printf("Enter data for node %d - ", i+1);
        scanf("%d", d);
        CreateNode(d);
    }
}