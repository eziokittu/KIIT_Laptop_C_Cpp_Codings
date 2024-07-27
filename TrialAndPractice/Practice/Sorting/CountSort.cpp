#include <iostream>
#include <vector>

using namespace std;

// Best suitable if the range of numbers (lowest to highest) is less
// The count of elements are stored in an array of size of the maximum element
void CountSort(vector<int> &arr, int n){
  int max=arr[0];
  // Getting the max
  for (int i=1; i<n; i++){
    if (arr[i]>max){
      max = arr[i];
    }
  }

  // getting the count for each distinct
  vector<int> count (max+1,0);
  for (int i=0; i<n; i++){
    count[arr[i]]++;
  }

  // updating the count array
  for (int i=1; i<=max; i++){
    count[i] = count[i] + count[i-1];
  }
  
  // traversing the array to get the sorted array
  int output[n];
  for (int i=n-1; i>=0; i--){
    output[--count[arr[i]]] = arr[i];
  }

  for (int i=0; i<n; i++){
    arr[i] = output[i];
  }
}

void PrintArr(vector<int> arr, string message){
  cout <<endl<<message<<endl;
  for (int i=0; i<arr.size(); i++){
    cout << arr[i] << " ";
  }
  cout<<endl;
}

int main(){
  vector<int> arr = {2,4,7,20,17,13,1,9,14,11,12,8};
  PrintArr(arr, "Before sorting:");
  CountSort(arr, arr.size());
  PrintArr(arr, "After sorting:");
}