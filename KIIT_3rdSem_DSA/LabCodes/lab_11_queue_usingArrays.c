// Implementation of QUEUE using Arrays

#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr; // integer array pointer
};
typedef struct Queue queue;

void CreateQueue(queue *q){
    printf ("Enter initial size of the stack : ");
    scanf("%d", &q->size);
    q->front = -1;
    q->rear = -1;
    printf("\nQueue is now created!");
}

void Enqueue(queue *q, int data){
    if (q->rear == q->size - 1){
        printf ("\nOverflow Condition!");
        return;
    }
    else if (q->rear == -1){
        q->front ++;
        q->rear ++;
    }
    else {
        q->rear ++;
    }
    printf("\nData [%d] enqueued.", data);
    q->arr[q->rear] = data;
}

int Dequeue(queue *q){
    int data;
    if (q->front == -1){
        printf("\nUnderflow Condition!");
        return -1;
    }
    data = q->arr [q->front];
    if (q->front == q->rear){
        // Last Data to be deleted
        q->front = -1;
        q->rear = -1;
    }
    else q->front++;
    printf("\nData [%d] dequeued.", data);
    return data;
}

void Display(queue *q){
    printf("\nPrinting the queue : ");
    if (q->front == -1){
        printf("[No Data]");
        return;
    }
    for (int i=q->front; i<=q->rear; i++)
        printf("%d ", q->arr[i]);
}

int main(){
    queue q;
    CreateQueue(&q);

    Enqueue(&q, 10);
    Enqueue(&q, 4);
    Enqueue(&q, 13);
    Enqueue(&q, 7);
    Display(&q);

    Dequeue(&q);
    Dequeue(&q);
    Display(&q);

    return 0;
}