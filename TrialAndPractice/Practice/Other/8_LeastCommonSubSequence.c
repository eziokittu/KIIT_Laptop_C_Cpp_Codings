#include <stdio.h>
#include <string.h>
#include <limits.h>

int max_of (int a, int b){
    return (a > b ? a : b);
}

// LCS without Memorization
// int LCS_1(char x[], char y[], int i, int j) {
//     if (x[i]==0 || y[j]==0){
//         // printf("--x[%d]=%c, x[%d]=%c, %d\n", i, x[i], j, y[j], (x[i]==0));
//         return 0;
//     }
//     if (x[i]==y[j]){
//         return 1+ LCS_1(x, y, i+1, j+1);
//     }
// }

// LCS with memorization
int LCS_2(char x[], char y[], int m, int n, int z[m+1][n+1]){
    for (int i=0; i<m+1; i++){
        for (int j=0; j<n+1; j++){
            if(i==0 || j==0){
                z[i][j] = 0;
            }
            else if (x[i-1]==y[j-1]){
                z[i][j] = z[i-1][j-1] + 1;
            }
            else {
                z[i][j] = max_of(z[i-1][j], z[i][j-1]);
            }
        }
    }

    printf("\nPrinting the table z:\n");
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            printf("%d\t", z[i][j]);
        }
        printf("\n");
    }

    printf(" [returing: z[%d][%d]\n ", m, n);
    return z[m][n];
}

int main() {
    // char s1[20] = "ABCDBCAD";
    // char s2[20] = "BBCDBCAD";
    char s1[20], s2[20];
    printf("Enter 1st string: ");
    scanf("%[^\n]%*c", s1);
    printf("Enter 2nd string: ");
    scanf("%[^\n]%*c", s2);

    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int m[l1+1][l2+1];

    // printf("Max length of sub sequence (using LCS_1): %d\n", LCS_1(s1, s2, 0, 0));
    printf("Max length of sub sequence (using LCS_2): %d\n", LCS_2(s1, s2, l1, l2, m));

    return 0;
}