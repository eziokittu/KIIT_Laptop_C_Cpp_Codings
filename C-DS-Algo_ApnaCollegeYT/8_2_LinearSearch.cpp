#include <iostream>

using namespace std;

// The Time Complexity of Linear Search is Big Oh (n)
int LinearSearch(int arr[], int size, int search)
{
    for (int i=0; i<size; i++)
    {
        if (arr[i] == search)
        {
            return i;
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
    cout << "The index of the element being searched is : " << LinearSearch(arr, n, search);

    return 0;
}