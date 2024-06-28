#include <iostream>

using namespace std;

// finding the max element up till arr[i] where i ranges from 0 to n
void Problem1(){
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i]; 
    }

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
}

// Sum of all sub arrays
void Problem2(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int sum = 0;
    for (int i=0; i<n; i++){
        int temp = 0;
        for (int j=i; j<n; j++){
            temp += arr[j];
            sum+=temp;
        }
    }
    cout<<sum;
}

// Longest Arithmetic SubArray
void Problem3(){
    
}

int main() {
    // Problem1();
    Problem2();
}