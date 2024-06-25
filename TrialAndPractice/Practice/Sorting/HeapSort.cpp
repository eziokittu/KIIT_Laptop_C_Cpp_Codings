#include <iostream>
#include <vector>

using namespace std;

// Utility function to print the array
void printTree(vector<int> arr){
  cout << "\nPrinting the Binary Tree (for the array):\n";
  int level = 1;
  int nodes = 0;
  for (int i=0; i<arr.size(); i++){
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

// Heapify - checks the left and right children if their value is greater than the root. if so, they swap
// Time Complexity - log(n)
void Heapify(vector<int> &arr, int n, int i){
  int left = 2*i + 1;
  int right = 2*i + 2;
  int largest = i;

  if (left<n && arr[left]>arr[largest]){
    largest = left;
  }
  if (right<n && arr[right]>arr[largest]){
    largest = right;
  }
  if (largest!=i){
    // Swap
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    Heapify(arr, n, largest);
  }
}

// Build Max Heap - creates max-heap from unsorted array (the top element is greater than both its left and right children)
// Time Complexity - n log(n)
void BuildMaxHeap(vector<int> &arr, int n){
  for (int i=(n/2)-1; i>=0; i--){
    Heapify(arr, n, i);
  }
}

// HeapSort
// Time Complexity - n log(n)
void HeapSort(vector<int> &arr, int n){
  int iteration = 0;
  BuildMaxHeap(arr, n);

  cout <<"\nMaking the Max Heap Tree:";
  printTree(arr);
  cout <<endl;

  for (int i=n-1; i>=0; i--){
    // Swap
    int temp = arr[i];
    arr[i] = arr[0];
    arr[0] = temp;
    Heapify(arr, i, 0);

    cout <<"Iteration ["<<++iteration<<"]: ";
    printTree(arr);
  }
}

int main() {
  vector<int> arr = {9,1,5,2,3,11,8,7};
  cout <<"\nBefore Heap Sort is done --";
  printTree(arr);

  cout<<"\n ---------------- Start -----------------\n";
  HeapSort(arr, arr.size());
  cout<<"\n ---------------- End -----------------\n";

  cout <<"\nAfter Heap Sort is done --";
  printTree(arr);
}

