#include <stdio.h>
#include <stdlib.h>

int TOP = -1;

Push(s, n, TOP, x){
    if (TOP == n-1){
        printf("Overflow Condition");
        exit(1);
    }
    TOP++;
    s [TOP] = x;
}

Pop(s, n, TOP){
    if (TOP == -1){
        printf("Underflow Condition");
        exit(1);
    }
    else{
        int y;
        y = s[TOP];
        TOP--;
        return y;
    }
}

int main(){
    // dynamic memory 
}