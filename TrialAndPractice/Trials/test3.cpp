// Heap Sort

#include <iostream>

using namespace std;

// Utility function to print the array
void printTree(int arr[], int n){
  cout << "\nPrinting the Binary Tree (for the array):\n";
  int level = 1;
  int nodes = 0;
  for (int i=0; i<n; i++){
    cout << arr[i] << "\t";
    nodes++;
    if (nodes == level){
      level *= 2;
      cout << endl;
      nodes = 0;
    }
  }
  cout << endl;
}

void Heapify(int arr[], int n, int a){
  int largest = a;
  int left = (a*2) + 1;
  int right = (a*2) + 2;

  if (left<n && arr[left]>arr[largest]){
    largest = left;
  }
  if (right<n && arr[right]>arr[largest]){
    largest = right;
  }

  if (largest!=a){
    swap(arr[a], arr[largest]);
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
    swap(arr[0], arr[i]);
    Heapify(arr, i, 0);
  }
}

int main() {
  int arr[] = {9,1,5,2,3,11,8,7};
  cout <<"\nBefore Heap Sort is done --";
  printTree(arr, 8);
  HeapSort(arr, 8);
  cout <<"\nAfter Heap Sort is done --";
  printTree(arr, 8);
}