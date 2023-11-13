#include <stdio.h>
#include <string.h>
#include <limits.h>

int max (int a, int b){
    return (a>b ? a : b);
}

// LCS using recursion without memory
// Demerits -
// Time Complexity --> O(2^n) --> exponential
// overlapping of funtion calls take place 
int LCS_1(char x[], char y[], int i, int j) {
    if (x[i]=='\0' || y[j]=='\0'){
        return 0;
    }
    else if (x[i]==y[j]){
        return 1 + LCS_1(x,y, i+1, j+1);
    }
    else {
        return max( LCS_1(x,y,i,j+1), LCS_1(x,y,i+1,j) );
    }
}

// LCS using recursion and memory (Dynamic Programming)
// uses a 2D matrix as memory
// removes the overlapping function calls
// Time Complexity --> O(n x m)

int LCS_2(char x[], char y[], int i, int j, int m, int n, int z[m][n]) {
    for (int i=0; i<m; i++){
        z[i][0] = 0;
    }
    for (int i=0; i<n; i++){
        z[0][i] = 0;
    }

    for (int i=1; i<m; i++){
        for (int j=1; j<n; j++){
            if (x[i] == y[j]){
                z[i][j] = z[i-1][j-1] + 1;
            }
            else {
                z[i][j] = max(z[i][j-1], z[i-1][j]);
            }
        }
    }
    
    printf("\nPrinting the table :\n");
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf("%d ", z[i][j]);
        }
        printf("\n");
    }

    return z[m-1][n-1];
}

int main() {
    // char s1[10] = {'c', 'b', 'c', 'a', 'b'};
    // char s2[10] = {'c', 'b', 'a', 'b', 'c', 'b'};
    // char s1[10] = {'a', 'b', 'c', 'd', 'e', 'f'};
    // char s2[10] = {'b', 'c', 'a', 'b', 'd', 'e', 'f'};
    char s1[] = "apbadbk";
    char s2[] = "abapak";
    int m = strlen(s1);
    int n = strlen(s2);
    int z[m][n];

    printf("\nLCS using recursion, without memorisation = %d\n", LCS_1(s1, s2, 0,0));
    printf("LCS using recursion, with memorisation (Dynamic Programming) = %d\n\n", LCS_2(s1, s2, 0,0, strlen(s1), strlen(s2), z));

    return 0;
}