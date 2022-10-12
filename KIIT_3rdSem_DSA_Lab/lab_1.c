// DSA LAB
// Q1) Linear Searching

#include <stdio.h>

int LinearSearch(int *arr, int n, int search){
    for (int i=0; i<n; i++)
        if (*(arr+i) == search) return i;
    return -1;
}

int main(){
    int n;
    printf("Enter size of the array - ");
    scanf("%d", &n);

    printf("Enter data for array -\n");
    int arr[n];
    for (int i=0; i<n; i++){
        printf("arr [%d] : ", i);
        scanf("%d", arr+i);
    }

    int search;
    printf("\nWhat to search? - ");
    scanf("%d", &search);
    
    // Linear Search - Time Complexity O(n)
    printf("The element %d is found at index %d", search, LinearSearch(arr, n, search));

    return 0;
}