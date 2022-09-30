#include <iostream>

using namespace std;

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

    // Printing the array BEFORE sorting
    cout << "Before sorting : ";
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    // Bubble sorting
    int end = 0;
    while (end < n){
        for (int i=0; i<n-end; i++){
            if (arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        end+=1;
    }

    // Printing the array AFTER sorting
    cout << "\nAfter Bubble sorting : ";
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}