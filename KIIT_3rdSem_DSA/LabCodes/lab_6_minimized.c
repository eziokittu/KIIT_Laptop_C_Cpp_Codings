// Q6 Minimized
// matrix multiplictaion
#include <stdio.h>
 
int main()
{
    // hardcoded 2d array
    int a[1][3] = { {1,2,3} };
    int b[3][2] = { {2,0}, {3,5}, {4,0} };
    
    int r1=1, c1=3, r2=3, c2=2;
    
    // initialize each element to 0
    int mul[r1][c2];
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            mul[i][j]=0;
        }
    }
    
    // matrix multiplication done here
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            int k, sum=0;
            for (k=0 ;k<c1; k++){
                sum += a[i][k]*b[k][j];
            }
            mul[i][j] = sum;
        }
    }
    
    printf("Printing 2d array 1\n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
    printf("Printing 2d array 2\n");
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    
    printf("Matrix multiplication array\n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            printf("%d ",mul[i][j]);
        }
        printf("\n");
    }

    return 0;
}
