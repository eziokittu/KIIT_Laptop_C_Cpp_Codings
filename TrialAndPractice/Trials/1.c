#include <stdio.h>
#include <limits.h>

int m[5][5];
int s[5][5];

void printMatrix(int mat[5][5], int n) {
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
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

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
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("Printing the s table -\n");
    printMatrix(s, n);

    printf("Optimal Parenthesis Expression: ");
    printOptimalParenthesis(1, n - 1);
    printf("\n");

    printf("Minimum cost of multiplication: %d\n", minCost);

    return 0;
}
