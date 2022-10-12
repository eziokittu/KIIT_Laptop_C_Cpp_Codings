// DSA LAB
// Q2) Binary Searching

#include <stdio.h>

int BinarySearch(int *arr, int n, int search){
    int s=0, e=n-1, mid;
    while (s<=e){
        mid = (s+e)/2;
        if (search == *(arr+mid)) return mid;
        else if (search < *(arr+mid)) e = mid-1;
        else s = mid+1;
    }
    return -1;
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

    int search;
    printf("\nWhat to search? - ");
    scanf("%d", &search);
    
    // Binary Search - Time Complexity O(n)
    printf("The element %d is found at index %d", search, BinarySearch(arr, n, search));

    return 0;
}