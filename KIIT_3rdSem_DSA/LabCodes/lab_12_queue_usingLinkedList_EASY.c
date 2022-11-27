// Implementing queues using Linked List
#include <stdio.h>
#include <stdlib.h>

// Defininng the node structure for a doubly linked list
struct singly_linked_list_ADT{
    struct singly_linked_list_ADT *prev; // not necessary in singly LL
    int data; // for integer type linked list
    struct singly_linked_list_ADT *next;
};
typedef struct singly_linked_list_ADT node;

node *front = NULL;
node *rear = NULL;

// Function for insertion of data in a QUEUE
void Enqueue(node *q, int data){
    // dynamically allocating the node
    node *temp = (node*) malloc (sizeof(node));
    if (temp == NULL) {
        printf("\nHeap Memory is full!");
        return;
    }
    temp->next = NULL;
    temp->data = data;
    temp->next = NULL;

    // linking temporary node with the linked list
    if (q==NULL){
        front = temp;
        rear = temp;
    }
    else {
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
    }
}

// Function for deletion of data from a QUEUE
int Dequeue(node *q){ // integer type because linkedlist is of integer type
    if (q == NULL) {
        printf("\nThere is no linked list for STACK!");
        return -1;
    }

    // deleting the first node of the doubly linked list
    node *p = q;
    p->prev = NULL;
    p->next = NULL;
    q = q->prev;
}

// Function to display the stack
void Display(node *q){
    if (q->rear==NULL){
        printf("\nQueue is empty!");
    }
    // Iterating the linked list from front node to rear node
    printf("\n\nPrinting the Linked List : \n");
    for (node *p = q->front; q->rear!=q->rear; p=p->next){
        printf("[Address: %p", p);
        printf(", Data: %d", p->data);
        printf(", Next: %p]   ", p->next);
    }
}

// Driver Code
int main(){
    queue* q1;

    Display(q1);
    Enqueue(q1, 5);
    Display(q1);
    Enqueue(q1, 7);
    Enqueue(q1, 8);
    Enqueue(q1, 9);
    Display(q1);
    Dequeue(q1);
    Display(q1);

    return 0;
}