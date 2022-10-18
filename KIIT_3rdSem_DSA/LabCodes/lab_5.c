// DSA LAB
// Q5) Selection Sorting

#include <stdio.h>
#include <limits.h>

void SelectionSorting(int *arr, int n){
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (*(arr+j) < *(arr+i)){
                int temp = *(arr+j);
                *(arr+j) = *(arr+i);
                *(arr+i) = temp;
            }
        }
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
    SelectionSorting(arr, n);
    printf("\nPrinting array after sorting -\n");
    Display(arr, n);

    return 0;
}