// Implementation of stack using single linked lists
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node node;

node *top = NULL;

void Push(int data){
    node *temp = (node*)malloc(sizeof(node));
    if (temp==NULL) printf("\nStack is full");
    else {
        temp->data = data;
        temp->next = top;
        top = temp;
        printf("\nElement [%d] pushed in Stack!", data);
    }
}

int Pop(){
    int x=-1;
    if (top == NULL){
        printf("\nStack is empty!");
    }
    else {
        node *temp = top;
        top = temp->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

void Display(){
    struct node* p;
    p = top;
    printf("\nPrinting Stack - ");
    while (p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }  
}

int StackTop(){
    if (top == NULL) return -1;
    else return top->data;
}

int IsEmpty(){
    if (!top){
        printf("\nStack is empty!");
        return 1;
    }
    else{
        printf("\nStack is not empty!");
        return 0;
    }
}

int IsFull(){
    node* temp = (node*) malloc (sizeof(node));
    int r = (temp) ? 1:0;
    free(temp);
    return r;
}

int main(){

    Push(10);
    Push(3);
    Push(7);
    Push(4);
    Push(9);
    Push(6);
    Push(3);
    Push(2);
    Display();

    printf("\nData popped = %d", Pop());
    Display();

    printf("\nData popped = %d", Pop());
    Display();

    return 0;
}