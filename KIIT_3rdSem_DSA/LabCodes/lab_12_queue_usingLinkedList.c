// Implementing queues using Linked List
#include <stdio.h>
#include <stdlib.h>

// Defininng the node structure for a singly linked list
struct linked_list_ADT{
    int data; // for integer type linked list
    struct linked_list_ADT *next;
};
typedef struct linked_list_ADT node;

// defining the structure for a queue implemented using linked lists
struct queue_ADT{
    node* front;
    node* rear;
};
typedef struct queue_ADT queue;

// Creating the queue
void CreateQueue(queue *q){
    q->front = NULL;
    q->rear = NULL;
}

// Function for insertion of data from a QUEUE
void Enqueue(queue *q, int data){
    // dynamically allocating the node
    node *temp = (node*) malloc (sizeof(node));
    if (temp == NULL) {
        printf("\nHeap Memory is full!");
        return;
    }
    
    temp->data = data;
    temp->next = NULL;

    // q->rear = temp;
    // printf(" p->rear = %p", q->rear);
    // printf(" temp = %p", temp);
    // linking temporary node with the linked list

    if (q->rear==NULL){ // for 1st node
        q->front = temp;
        q->rear = temp;
    }
    else { // if linked list already exists
        q->rear->next=temp;
        q->rear = temp;
    }
    printf("\nQueue is enqueued with data - %d", data);
}

// Function for deletion of data from a QUEUE
int Dequeue(queue *q){ // integer type because linkedlist is of integer type
    if (q->front == NULL) {
        printf("\nThere is no linked list for STACK!");
        return -1;
    }

    // deleting the first node of the doubly linked list
    node* first = q->front;
    q->front = first->next;
    first->next = NULL;

    int data = first->data;
    free(first);
    first = NULL;
    return data;
}

// Function to display the stack
void Display(queue *q){
    if (q->front==NULL){
        printf("\nQueue is empty! Nothing to display");
        return;
    }

    // Iterating the linked list from front node to rear node
    printf("\n\nPrinting the Linked List : \n");
    node *p = q->front;
    do {
        printf("[Address: %p", p);
        printf(", Data: %d", p->data);
        printf(", Next: %p]\n", p->next);
        p = p->next;
    }
    while (p!=NULL);
}

// Driver Code
int main(){
    queue *q1;
    CreateQueue(q1);

    Display(q1);
    Enqueue(q1, 5);
    Enqueue(q1, 6);
    Display(q1);
    Enqueue(q1, 7);
    Enqueue(q1, 8);
    printf("\nQueue is dequeued - %d", Dequeue(q1));
    Enqueue(q1, 9);
    Display(q1);
    printf("\nQueue is dequeued - %d", Dequeue(q1));
    Display(q1);

    return 0;
}