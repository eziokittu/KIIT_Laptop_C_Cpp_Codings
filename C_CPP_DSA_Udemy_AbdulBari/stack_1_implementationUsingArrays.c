#include <stdio.h>

// implementing stack using Arrays
typedef struct{
    int size; // size of te array
    int TOP;
    int *s; // s means an integer array pointer
}stack;

int main(){
    stack st; // declaring thee stack from the struct

    // getting the initial size of the 
    printf("Enter size of the stack - ");
    scanf("%d", st.size);

}