// LeetCode Problem 907 - Sum of Subarray Minimums
// https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20

// MONOTONIC STACK needs to be used -- INCOMPLETE

#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b){
    return (a<b ? a : b);
}

void display(vector<vector<int>> v){
    cout << "\nDisplaying the 2d array:\n";
    for (auto row : v){
        for (int num : row){
            cout << num << " ";
        }
        cout << endl;
    }
}

int sumSubarrayMins(vector<int>& arr) {        
    int sum = 0;

    // defining a 2d vector of cost table with all values set to high value
    // vector<vector<int>> cost(arr.size(), vector<int>(arr.size(), 99999));
    vector<vector<int>> cost;
    for (int i=arr.size(); i>0; i--){
        cost.push_back(vector<int>(i, 99999));
    }

    // filling the diagonal elements
    for (int i=0; i<arr.size(); i++){
        cost[i][0] = arr[i];
        sum += cost[i][0];
    }
    
    // display
    // display(cost);

    // filling the top right triangular matrix / other elements
    for (int i=1; i<arr.size(); i++){
        for (int j=0; j<arr.size()-i; j++){
            cost[j][i] = min(cost[j][i-1], cost[j+1][i-1]);
            // printf("arr[%d][%d] = min(cost[%d][%d], cost[%d][%d])  ", j,i,  j,i-1,  j+1,i-1);
            sum += cost[j][i];
        }
        // cout<<endl;
    }
    
    // display
    // display(cost);

    return sum;
}

int main()
{
    vector<int> nums1 = {11,81,94,43,3};
    vector<int> nums2 = {3, 1, 2, 4};
    cout<<sumSubarrayMins(nums1)<<endl;
    cout<<sumSubarrayMins(nums2)<<endl;
    // cout<<sumSubarrayMins(nums1)<<endl;

    return 0;
}