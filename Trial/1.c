#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a;
    a = (int*) malloc (5*sizeof(int));
    for (int i=0; i<5; i++){
        a[i] = i;
    }
    for (int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
}