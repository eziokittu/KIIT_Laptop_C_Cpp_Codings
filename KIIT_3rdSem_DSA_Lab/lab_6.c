// Q6 Minimized
// matrix multiplictaion
#include <stdio.h>

void MatrixMultiplication(int **mul, int **arr1, int **arr2, int r1, int c1, int r2, int c2){
    
    // initialize each element to 0 for the 3rd 2D array
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            *(*(mul+i)+j)=0;
        }
    }

    // matrix multiplication done here
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            int k, sum=0;
            for (k=0 ;k<c1; k++){
                sum += (*(*(arr1+i)+k)) * (*(*(arr1+k)+j));
            }
            *(*(mul+i)+j) = sum;
        }
    }
}

void GetArray(int **arr[], int r, int c){
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            prinf("arr[%d][%d] = ", i,j);
            scanf("%d", (*(arr+i)+j));
        }
    }
}

void ShowArray(int **arr[], int r, int c){
    printf("\nPrinting 2d array 1\n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%d ", *(*(arr+i)+j) );
        }
        printf("\n");
    }
}

int main()
{
    int r1,c1, r2,c2;

    printf("\nEnter rows and cols for 1st 2D array:\n");
    scanf("%d%d", &r1, &c1);
    int arr1[r1][c1];
    GetArray(&arr1, r1, c1);

    printf("\nEnter rows and cols for 2nd 2D array:\n");
    scanf("%d%d", &r2, &c2);
    int arr2[r2][c2];
    GetArray(&arr2, r2, c2);
    
    // if matrix multiplication is possible
    if (c1!=r2){
        printf("\nMatrix multiplication not possible. Try Again!\n");
        main();
    }

    // mul array declared
    int mul[r1][c2];
    MatrixMultiplication(&mul, &arr1, &arr2, r1, c1, r2, c2);
    
    ShowArray(&arr1, r1, c1);
    ShowArray(&arr2, r2, c2);
    ShowArray(&arr2, r1, c2);

    return 0;
}