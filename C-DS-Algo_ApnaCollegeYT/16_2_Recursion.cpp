#include <iostream>

using namespace std;

// Problem 1 - check if array is sorted or not
bool checkIfSorted(int arr[], int n){
  if (n==1){
    return true;
  }
  bool remainingArr = checkIfSorted(arr+1, n-1);
  return (arr[0]<=arr[1] && remainingArr);
}

// Problem 2 - print numbers in a range in decreasing order
void PrintDecreasing(int n){
  if (n<1){
    cout<<endl;
    return;
  }
  cout << n << " ";
  PrintDecreasing(n-1);
}

// Problem 3 - print numbers in a range in increasing order
void PrintIncreasing(int n){
  if (n<1){
    return;
  }
  PrintIncreasing(n-1);
  cout << n << " ";
}

// Problem 4 - Find the first occurence of a number in an array
int FindOccurenceFirst(int arr[], int n, int i, int key){
  if (i==n){
    return -1;
  }
  if (arr[i]==key){
    return i;
  }
  FindOccurenceFirst(arr, n, i+1, key);
}

// Problem 5 - Find the last occurence of a number in an array
int FindOccurenceLast(int arr[], int n, int i, int key, int found){
  if (i==n){
    return found;
  }
  if (arr[i]==key){
    found = i;
  }
  FindOccurenceFirst(arr, n, i+1, key);
}
int FindOccurenceLast(int arr[], int n, int i, int key){
  int restArr = FindOccurenceLast(arr, n, i+1, key);
  if (restArr!=-1){
    return restArr;
  }
  if (arr[i]==key){
    return i;
  }
  return -1;
}

int main(){
  int arr1[] = {1,2,6};
  cout << (checkIfSorted(arr1,3)==true ? "sorted" : "not sorted") << endl;

  PrintDecreasing(5);
  PrintIncreasing(5);
  cout<<endl;

  int arr2[] = {3,5,4,3,7,2,4};
  cout << FindOccurenceFirst(arr2, 7, 0, 3) <<endl;
  cout << FindOccurenceFirst(arr2, 7, 0, 11) <<endl;
  cout << FindOccurenceLast(arr2, 7, 0, 3, -1) <<endl;
  cout << FindOccurenceLast(arr2, 7, 0, 11, -1) <<endl;
}