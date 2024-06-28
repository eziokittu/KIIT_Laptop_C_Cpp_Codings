#include <stdio.h>

int Partition(int arr[], int left, int right){
    int pivot = arr[left];
    int i = left+1;
    int j = right;

    while (i<=j){
        while (i<=j && arr[i]<=pivot){
            i++;
        }
        while (i<=j && arr[j]>=pivot){
            j--;
        }

        if (i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[j];
    arr[j] = arr[left];
    arr[left] = temp;

    return j;
}

void QuickSort(int arr[], int left, int right){
    if (right-left > 0){
        int index = Partition(arr, left, right);
        QuickSort(arr, left, index-1);
        QuickSort(arr, index+1, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    QuickSort(arr, 0, n-1);

    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}