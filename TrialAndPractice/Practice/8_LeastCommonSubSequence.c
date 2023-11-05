#include <stdio.h>
#include <limits.h>

int z[6][7];

int LCS(char x[], char y[], int i, int j) {
    if (x[i]==y[j]){
        z[i][j] = LCS(x,y, i-1, j-1)+1
    }
}

int main() {
    int m[6][7];

    char s1[10] = {'c', 'b', 'c', 'a', 'b'};
    char s2[10] = {'c', 'b', 'a', 'b', 'c', 'a'};

    // filling the 2d table with initial values
    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            if(i==0 || j==0){
                m[i][j] = 0;
            }
            else {
                m[i][j] = -1;
            }
        }
    }

    return 0;
}