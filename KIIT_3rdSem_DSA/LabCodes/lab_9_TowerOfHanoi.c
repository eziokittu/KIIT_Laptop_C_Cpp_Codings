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
void CreateStack(stack *st, int size){
    // getting the initial size of the 
    st->size = size;
    st->top = -1;
    st->s = (int*) malloc (st->size*sizeof(int));
}

void Push(stack *st, int data){
    // Checking Overflow condition
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
        printf("\nPop() used in stack.");
        x = st->s[st->top--];
    }
    return x;
}

void Display(stack st){
    printf(" Stack: ");
    for (int i=st.top; i>=0; i--){
        printf("%d ",st.s[i]);
    }
}

int main(){
    stack *a, *b, *c;
    int n;
    printf("Enter no. of disks in Tower of Hanoi : ");
    scanf("%d", &n);
    CreateStack(&a, n);
    CreateStack(&b, n);
    CreateStack(&c, n);
    for (int i=1; i<=n; i++) Push(&a, i);
    Display(*a);
    Display(*b);
    Display(*c);

    return 0;
}