#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
    int arr_size;
    cout << "\nEnter size of the array : ";
    cin >> arr_size;

    // entering elements in the array
    int arr[arr_size];
    cout << "\nEnter elements in the array ---- \n";
    for (int i=0; i<arr_size; i++)
    {
        cout << "Element [" << i << "] : ";
        cin >> arr[i]; 
    }

    // Printing elements in the array
    cout << "\nAll the elements of the array are in order :--\n";
    for (int i=0; i<arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    string s;
    cout << "\n\nDo you want to try again? [Y for YES, N for NO, else = NO] : ";
    getline(cin, s);
    getline(cin, s);
    if (s == "Y" || s=="YES" || s=="yes"){
        main();
    }
}