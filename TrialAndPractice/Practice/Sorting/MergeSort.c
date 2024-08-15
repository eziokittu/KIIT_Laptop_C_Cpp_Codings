// Merge Sort

#include <stdio.h>

void Merge (int arr[], int left, int mid, int right){
  int s1 = mid-left+1, s2 = right-mid;
  int arr1[s1], arr2[s2];
  int i, j, k=0;
  for (i=left; i<=mid; i++){
    arr1[k++] = arr[i];
  }
  k=0;
  for (j=mid+1; j<=right; j++){
    arr2[k++] = arr[j];
  }

  i=0, j=0, k=left;
  while (i<s1 && j<s2){
    if (arr1[i] < arr2[j]){
      arr[k++] = arr1[i++];
    }
    else {
      arr[k++] = arr2[j++];
    }
  }

  while (i<s1){
    arr[k++] = arr1[i++];
  }

  while (j<s2){
    arr[k++] = arr2[j++];
  }
}

void MergeSort(int arr[], int left, int right){
  int mid = (left + right) / 2;
  if (mid-left>1){
    MergeSort(arr, left, mid);
  }
  if (right-mid>1){
    MergeSort(arr, mid+1, right);
  }
  Merge(arr, left, mid, right);
}

int main() {
  int arr[] = {4,79,1,21,8,3,6,2,7,44,11,12,62,10};
  int n = 14;
  printf("Before Merge Sort: ");
  for (int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  MergeSort(arr, 0, 13);
  printf("\nAfter Merge Sort: ");
  for (int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
}