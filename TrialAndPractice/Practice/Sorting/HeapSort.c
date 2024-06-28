#include <stdio.h>

void Heapify(int arr[], int n, int a){
  int largest = a;
  int left = (a*2) + 1;
  int right = (a*2) + 2;

  if (left<n && arr[left] > arr[largest]){
    largest = left;
  }
  if (right<n && arr[right] > arr[largest]){
    largest = right;
  }

  // Swap
  if (largest != a){
    int temp = arr[a];
    arr[a] = arr[largest];
    arr[largest] = temp;

    Heapify(arr, n, largest);
  }
}

void BuildMaxHeap(int arr[], int n){
  for (int i=(n/2)-1; i>=0; i--){
    Heapify(arr, n, i);
  }
}

void HeapSort(int arr[], int n){
  BuildMaxHeap(arr, n);

  for (int i=n-1; i>=0; i--){
    // Swap
    int temp = arr[i];
    arr[i] = arr[0];
    arr[0] = temp;

    Heapify(arr, i, 0);
  }
}

int main(){
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  HeapSort(arr, n);

  for (int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
}