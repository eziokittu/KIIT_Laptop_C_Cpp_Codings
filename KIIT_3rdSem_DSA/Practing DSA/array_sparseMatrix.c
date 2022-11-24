#include <stdio.h>
#include <stdlib.h>

void AddMatrices(int a[4][4], int b[4][4]){
    int sum[4][4];
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            printf("%d", sum[i][j]);
        }
        printf("\n");
    }
    return sum;
}

void AddSparceMatrices(int a[4][4], int b[4][4]){
    
}

int main(){
    int a[4][4] = {
        {0,0,0,1},
        {2,0,0,0},
        {3,0,2,0},
        {5,7,0,9}
    };
    printf("\n----a----\n");
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    int b[4][4] = {
        {0,3,0,4},
        {2,0,0,0},
        {5,0,3,1},
        {1,0,0,0}
    };
    printf("\n----b----\n");
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            printf("%d", b[i][j]);
        }
        printf("\n");
    }
    printf("\n---sum---\n");
    AddMatrices(a, b);
}