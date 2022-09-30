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

    // Selection sorting
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    // Printing the array AFTER sorting
    cout << "\nAfter Selection sorting : ";
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}