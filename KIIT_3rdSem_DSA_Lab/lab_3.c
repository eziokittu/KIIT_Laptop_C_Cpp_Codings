// DSA LAB
// Q3) Insertion Sorting

#include <stdio.h>

void InsertionSorting(int *arr, int n){
    for (int i=1; i<n; i++){
        int temp = *(arr+i);
        int j = i-1;
        while (*(arr+j) > temp && j>=0){
            *(arr+j+1) = *(arr+j);
            j--;
        }
        *(arr+j+1) = temp;
    }
}

void Display(int *arr, int n){
    for (int i=0; i<n; i++){
        printf("%d ", *(arr+i));
    }
}

int main(){
    int n;
    printf("Enter size of the array - ");
    scanf("%d", &n);

    printf("Enter data for array, sorted in ascending order -\n");
    int arr[n];
    for (int i=0; i<n; i++){
        printf("arr [%d] : ", i);
        scanf("%d", arr+i);
    }

    printf("\nPrinting array before sorting -\n");
    Display(arr, n);
    InsertionSorting(arr, n);
    printf("\nPrinting array after sorting -\n");
    Display(arr, n);

    return 0;
}