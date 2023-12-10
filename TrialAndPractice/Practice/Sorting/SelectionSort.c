#include <stdio.h>
#include <limits.h>

int main() {
    int n=10;
    int arr[10] = {7,2,4,0,3,9,8,5,6,1};

    printf("Selection Sort\n");
    printf("\nPrinting Before Sorting:");
    for (int i=0; i<n; i++){
        printf(" %d", arr[i]);
    }

    for (int i=0; i<n; i++){
        int min = arr[i];
        int index = i;
        for (int j=i+1; j<n; j++){
            if (arr[j] < min){
                min = arr[j];
                index = j;
            }
        }
        if (index != i){
            arr[index] = arr[i];
            arr[i] = min;
        }
    }

    printf("\nPrinting After Sorting:");
    for (int i=0; i<n; i++){
        printf(" %d", arr[i]);
    }
    
    return 0;
}