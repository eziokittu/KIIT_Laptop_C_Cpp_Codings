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

    // finding the max element up till arr[i] where i ranges from 0 to n
    int arr2[n];
    int pos = 0;
    int max = arr[0];
    while (pos < n)
    {
        for (int i=0; i<=pos; i++)
        {
            if (max < arr[i]) max = arr[i];
        }
        arr2[pos] = max;
        pos += 1;
    }

    // Printint the 2nd array
    for (int i=0; i<n; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}