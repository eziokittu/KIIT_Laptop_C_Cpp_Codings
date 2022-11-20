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

// Function to create Stack for the 1st time
void CreateStack(stack *st, int s, char c){
    st->name = c;
    st->size = s;
    st->top = -1;
    st->s = (int*) malloc (st->size*sizeof(int));
    // for (int i=1; i<=s; i++){
    //     st->s[i-1] = i;
    // }
    st->s[0] = 1;
    st->s[1] = 2;
    st->s[2] = 3;
}

void Push(stack *st, int data){
    if (st->top == st->size-1){
        printf("\nStack Overflow!");
    }
    else {
        st->top++;
        st->s[st->top] = data;
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

void Display(stack st){
    printf("\n%c - ", st.name);
    for (int i=st.top; i>=0; i--){
        printf("%d ",st.s[i]);
    }
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
    CreateStack(&M, disks, 'M');
    CreateStack(&R, disks, 'R');

    Display(L);
    Display(M);
    Display(R);
    TOH (&L, &M, &R, disks);
    Display(L);
    Display(M);
    Display(R);

    return 0;
}