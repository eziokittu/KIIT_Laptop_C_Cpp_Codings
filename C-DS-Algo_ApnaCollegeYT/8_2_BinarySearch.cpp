#include <iostream>

using namespace std;

// The Time Complexity of Binary Search is Big Oh (Log of n base 2)
int BinarySearch(int arr[], int size, int search)
{
    int start = 0;
    int end = size-1;
    
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == search){
            return mid;
        }

        else if (arr[mid] > search){
            end = mid - 1;
        }

        else if (arr[mid] < search){
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    cout << "Enter size of the array : ";
    int n;
    cin >> n;
    int arr[n];

    // entering elements in the array
    cout << "\nEnter elements in the array ---- \n";
    for (int i=0; i<n; i++)
    {
        cout << "Element [" << i << "] : ";
        cin >> arr[i]; 
    }

    // which element to search for ?
    int search;
    cout << "Enter the data to search for : ";
    cin >> search;

    // Linear Search
    cout << "The index of the element being searched is : " << BinarySearch(arr, n, search);

    return 0;
}