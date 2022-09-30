// Subarrays Challange 1
// print all posible sub arrays from an array

#include <iostream>
#include <climits>
using namespace std;

int main(){
    // taking an array
    int n;
    cout << "Enter range : ";
    cin >> n;
    int arr[n];
    cout << "Enter data for array : ";
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    // Brute force method - Time Complexity of O(n^3)
    // Printing all the sub arrays
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            for (int k=i; k<=j; k++){   
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }

    // Cumulative Sum approach
    int currSum[n+1];
    currSum[0] = 0;
    for (int i=1; i<=n; i++){
        currSum[i] = currSum[i-1] + arr[i-1];
    }

    int maxSum = INT_MIN;
    for (int i=0; i<n; i++){
        int sum = 0;
        for (int j=0; j<i; j++){
            sum = currSum[i] - currSum[j];
            maxSum = max(sum, maxSum);
        }
    }

    cout << maxSum;

    return 0;
}