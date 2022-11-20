// DSA Lab Code - Tower of Hanoi
#include <stdio.h>
#include <stdlib.h>

// Defining the structure for a stack using Arrays
struct stackADT {
    char name; // name of stack
    int size; // size of the stack
    int top; // top of the stack
    int *s; // an integer array using pointer
};

typedef struct stackADT stack;

void Display(stack *st){
    printf("\n%c - ", st->name);
    if (st->top == -1){
        printf("[EMPTY]");
        return;
    }
    for (int i=st->top; i>=0; i--){
        printf("%d ",st->s[i]);
    }
}

// Function to create Stack for the 1st time
void CreateStack(stack *st, int s, char c){
    st->name = c;
    st->size = s;
    st->top = -1;
    st->s = (int*) malloc (st->size*sizeof(int));
}

void Push(stack *st, int data){
    if (st->top == st->size-1){
        printf("\nStack Overflow!");
    }
    else {
        st->s[++(st->top)] = data;
    }
}

int Pop(stack *st){
    int x=0;
    // Checking Undeflow condition
    if (st->top == -1){
        printf("\nStack Undeflow!");
    }
    else {
        x = st->s[st->top--];
    }
    return x;
}

// Tower of Hanoi using Recursion
void TOH(stack *L, stack *M, stack *R, int n){
    if (n==0)
        return;
    else{
        TOH(L, R, M, n-1);
        printf ("\n%c -> %c", L->name, R->name);
        int x = Pop(L);
        Push(R, x);
        TOH(M, L, R, n-1);
    }
}

int disks = 3;
stack L, M, R;

int main(){
    CreateStack(&L, disks, 'L');
    for (int i=1; i<=disks; i++){
        Push(&L, i);
    }
    CreateStack(&M, disks, 'M');
    CreateStack(&R, disks, 'R');

    printf("\n--- Printing Stack ---");
    Display(&L);
    Display(&M);
    Display(&R);

    printf("\n\n--- Tower of Hanoi Steps ---");
    TOH (&L, &M, &R, disks);

    printf("\n\n--- Printing Stack ---");
    Display(&L);
    Display(&M);
    Display(&R);

    return 0;
}