// DSA Lab Code - Stacks using arrays
#include <stdio.h>
#include <stdlib.h>

// Defining the structure for a stack using Arrays
typedef struct {
    int size; // size of the stack
    int top; // top of the stack
    int *s; // an integer array using pointer
} stack;

// Function to create Stack for the 1st time
void CreateStack(stack *st){
    // getting the initial size of the 
    printf("Enter size of the stack - ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int*) malloc (st->size*sizeof(int));
}

void Push(stack *st){
    // Checking Overflow condition
    if (st->top == st->size-1){
        printf("\nStack Overflow!");
    }
    else {
        int data;
        st->top++;
        printf("Enter data to PUSH : ");
        scanf("%d", &data);
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
        printf("\nPop() used in stack.");
        x = st->s[st->top--];
    }
    return x;
}

int Peek(stack st, int pos){
    int x=-1;
    if (st.top-pos<0)
        printf("Invalid Position!");
    x = st.s[st.top-pos+1];
    return x;
}

int IsFull(stack st){
    if (st.top==st.size-1) return 1;
    else return 0;
}

int IsEmpty(stack st){
    if (st.top==-1) return 1;
    else return 0;
}

void Display(stack st){
    printf("\n----- Printing Stack -----");
    for (int i=st.top; i>=0; i--){
        printf("%d ",st.s[i]);
    }printf("\n");
}

int main(){
    stack st;
    CreateStack(&st);
    if (IsEmpty(st)) printf("Stack is empty now!\n");
    for (int i=0; i<5; i++){
        Push(&st);
    }
    Display(st);
    printf("Data in pos[2] of stack: %d", Peek(st, 2));
    Pop(&st);
    Display(st);

    return 0;
}