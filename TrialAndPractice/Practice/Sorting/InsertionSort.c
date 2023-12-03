#include <stdio.h>
#include <limits.h>

int main() {
    int n=10;
    int arr[10] = {7,2,4,0,3,9,8,5,6,1};

    printf("Insertion Sort\n");
    printf("\nPrinting Before Sorting:");
    for (int i=0; i<n; i++){
        printf(" %d", arr[i]);
    }

    for (int i=1; i<n; i++){
        int temp = arr[i];
        for (int j=i-1; j>=0; j--){
            if (arr[j] > temp){
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
            else{
                break;
            }
        }
    }

    printf("\nPrinting After Sorting:");
    for (int i=0; i<n; i++){
        printf(" %d", arr[i]);
    }
    
    return 0;
}