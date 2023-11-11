#include <stdio.h>
#include <limits.h>

int z[6][7];

int max_of (int a, int b){
    return (a > b ? a : b);
}

// LCS without Memorization
int LCS_1(char x[], char y[], int i, int j) {
    if (x[i]==y[j]){
        return 1+ LCS_1(x, y, i+1, j+1);
    }
    else{
        return max_of(LCS_1(x, y, i+1, j), LCS_1(x, y, i, j+1));
    }
}

int main() {
    int m[6][7];

    char s1[10] = "CBCAB";
    char s2[10] = "CCBCBCACB";

    // filling the 2d table with initial values
    // for(int i=0; i<6; i++){
    //     for(int j=0; j<7; j++){
    //         if(i==0 || j==0){
    //             m[i][j] = 0;
    //         }
    //         else {
    //             m[i][j] = -1;
    //         }
    //     }
    // }

    printf("Max length of sub sequence: %d", LCS_1(s1, s2, 0, 0));

    return 0;
}