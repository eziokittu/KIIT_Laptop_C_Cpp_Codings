#include <stdio.h>
#include <limits.h>



int main() {
    int n=10;
    int arr[10] = {7,2,4,0,3,9,8,5,6,1};

    printf("\nPrinting After Sorting:");
    for (int i=0; i<n; i++){
        printf(" %d", arr[i]);
    }
    
    return 0;
}