#include <iostream>
#include <vector>

using namespace std;

// utility function to print the array
void PrintArray(vector<int> arr){
  cout <<"\nPrinting the array: ";
  for (auto i : arr){
    cout << i << " ";
  }
}

int Partition(vector<int> &arr, int left, int right){
  int i=left+1, j=right;
  int pivot = left;
  while (i<j){
    while (i <= j && arr[i] <= arr[pivot]) {
      i++;
    }
    while (i <= j && arr[j] >= arr[pivot]) {
      j--;
    }

    if (i<j){
      // Swap
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  // Swapping the pivot element to its correct position
  int temp = arr[j];
  arr[j] = arr[pivot];
  arr[pivot] = temp;

  return j;
}

void QuickSort(vector<int> &arr, int left, int right){
  // atleast 2 elements present
  if (left < right){
    int index = Partition(arr, left, right);
    QuickSort(arr, left, index-1);
    QuickSort(arr, index+1, right);
  }
}

int main() {
  vector<int> arr = {3,9,2,7,6,8,1,4,5};
  cout <<"\nBefore Quick Sort:";
  PrintArray(arr);

  QuickSort(arr,0,arr.size()-1);
  cout <<"\nAfter Quick Sort:";
  PrintArray(arr);
}