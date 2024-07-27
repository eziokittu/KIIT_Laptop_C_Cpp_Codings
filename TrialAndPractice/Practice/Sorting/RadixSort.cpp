#include <iostream>
#include <vector>

using namespace std;

// Using Countsort with memory of 10 (for decimal numbers)
void CountSort(vector<int> &arr, int n, int div){
  int max=9;

  // getting the count for each distinct
  vector<int> count (max+1,0);
  for (int i=0; i<n; i++){
    count[ (arr[i]/div)%10 ]++;
  }

  // updating the count array
  for (int i=1; i<=max; i++){
    count[i] = count[i] + count[i-1];
  }
  
  // traversing the array to get the sorted array
  int output[n];
  for (int i=n-1; i>=0; i--){
    output[--count[(arr[i]/div)%10 ]] = arr[i];
  }

  for (int i=0; i<n; i++){
    arr[i] = output[i];
  }
}

int GetMax(vector<int> arr, int n){
  int max = arr[0];
  for (int i=0; i<n; i++){
    if (arr[i] > max){
      max = arr[i];
    }
  }
  return max;
}

void RadixSort(vector<int> arr, int n){
  int max = GetMax(arr, n);
  for (int div=1; div<=max; div*=10){
    CountSort(arr, n, div);
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
  // vector<int> arr = {2,4,7,20,17,13,1,9,14,11,12,8};
  // vector<int> arr = {5,2,3,1};
  vector<int> arr = {-4,0,-1,2,-3};
  PrintArr(arr, "Before sorting:");
  RadixSort(arr, arr.size());
  PrintArr(arr, "After sorting:");
}