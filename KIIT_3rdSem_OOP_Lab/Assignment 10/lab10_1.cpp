// OOPs LAB Assignment 10
// Q1) WAP to find sort an integer array and a float
// array, using function template

#include <iostream>
using namespace std;

template <typename T> void SortArray(T *arr, int n=10){
    // Bubble Sorting
	for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            if (arr[i]>arr[j]){
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template <typename T> void Display(T *arr, int n=10){
    cout << "\n--- Displaying ---";
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main()
{
	int arr1[] = {2,4,3,9,1,6,8,7,5,0};
	float arr2[] = {1.2, 8.4, 8.43, 8.39, 1.1};

    cout <<"----- Before Soring -----";
    Display(arr1);
    Display(arr2, 5);

    SortArray(arr1);
    SortArray(arr2, 5);

    cout <<"\n\n----- After Soring -----";
    Display(arr1);
    Display(arr2, 5);

	return 0;
}
