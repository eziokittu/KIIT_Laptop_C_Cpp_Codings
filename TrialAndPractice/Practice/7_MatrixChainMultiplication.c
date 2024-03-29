// Dynamic Programming - Matrix Chain Multiplication

// table method
// 2 tables used - m, s

// EXAMPLE -
//  A1 A2 A3 A4
// {5, 4, 6, 2, 7}
// m[i, j] = min { m[i, k] + m[k+1, j] + ( d(i-1)*d(k)*d(j) )}

#include <stdio.h>
#include <limits.h>

int m[5][5];
int s[5][5];

void printMatrix(int n, int mat[n][n]) {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void printOptimalParenthesis(int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(i, s[i][j]);
        printOptimalParenthesis(s[i][j] + 1, j);
        printf(")");
    }
}

int MCM(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int chainLen = 2; chainLen < n; chainLen++) {
        for (int i = 1; i < n - chainLen + 1; i++) {
            int j = i + chainLen - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int n = 5;
    int arr[n];
    printf("Enter the '%d' sizes for the arrays: ", n);
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }

    int minCost = MCM(arr, n);

    printf("\nPrinting the m table -\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            printf("%d\t ", m[i][j]);
        }
        printf("\n");
    }

    printf("Printing the s table -\n");
    printMatrix(n, s);

    printf("Optimal Parenthesis Expression: ");
    printOptimalParenthesis(1, n - 1);
    printf("\n");

    printf("Minimum cost of multiplication: %d\n", minCost);

    return 0;
}
