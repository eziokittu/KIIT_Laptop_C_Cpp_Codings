// Name - Bodhisatta Bhattacharjee
// CSE-41 --- 22057025
// DSA LAB Sessional

// Question set - 5

// Q1) stack and it's operations using array

#include <stdio.h>
#include <stdlib.h>

// Defining the structure for STACK ADT
struct StackADT{
	int size; // size of stack
	int top; // top of the stack
	int *s; // integer type array
};
typedef struct StackADT stack;

// function to create a stack
void CreateStack(stack *st){
	// getting the size of the stack
	int size;
	printf("\nEnter Size of the stack : ");
	scanf("%d", &size);
	st->size = size;
	
	// dynamically allocating the array of the stack
	st->s = (int*) malloc (st->size * sizeof(int));
	
	// initiating the top of the stack
	st->top = -1;
	
	printf("\nStack is created!");
}

// function to check is a stack is full or not
int isFull(stack *st){
	if (st->top == st->size-1){
		return 1;
	}
	return 0;
}

// function to check is a stack is empty or not
int isEmpty(stack *st){
	if (st->top == -1){
		return 1;
	}
	return 0;
}

// function to perform insertion in a stack
void Push(stack* st, int data){
	if (isFull(st)){
		printf("\nStack Overflow!");
	}
	st->s[++st->top] = data;
}

// function to perform deletion in a stack
int Pop(stack *st){
	if (isEmpty(st)){
		printf("\nStack Underflow!");
	}
	int data = st->s[st->top--];
	return data;
}

void Display(stack *st){
	printf("\nDisplaying the stack : ");
	int i;
	for (i=0; i<=st->top; i++){
		printf("%d ", st->s[i]);
	}
}

int main(){
	stack *s1;
	CreateStack(&s1);
	Push(&s1, 10);
	Push(&s1, 13);
	Push(&s1, 16);
	Push(&s1, 70);
	Display(&s1);
	Pop (&s1);
	Pop (&s1);
	Display(&s1);
	
	return 0;
}