// LeetCode Problem 118 - Pascals Triangle
// https://leetcode.com/problems/pascals-triangle/

#include <iostream>
#include <vector>

using namespace std;

void getNums(int a, int row, vector<vector<int>>& nums){
    if (a>=row){
        // cout << "Test6\n";
        return;
    }
    vector<int> s;
    if (a==0){
        s.push_back(1);
        // cout << "Test3\n";
        nums.push_back(s);
        getNums(1, row, nums);
    }
    else if (a==1){
        s.push_back(1);
        s.push_back(1);
        // cout << "Test4\n";
        nums.push_back(s);
        getNums(2, row, nums);
    }
    else{
        // cout << "Test4.1\n";
        for (int i=0; i<=a; i++){
            // cout << "Test4.2\n";
            if (i==0 || i==a){
                // cout << "Test4.3\n";
                s.push_back(1);
            }
            else{
                // cout << "Test4.4\n";
                s.push_back(nums[a-1][i-1] + nums[a-1][i]);
                // cout << "Test4.6\n";
            }
            // cout << "Test4.5\n";
        }
        // cout << "Test5\n";
        nums.push_back(s);
        getNums(++a, row, nums);
    }
}

vector<vector<int>> generate(int r) {
    vector<vector<int>> nums;
    // cout << "Test2\n";
    getNums(0, r, nums);
    // cout << "Test7\n";
    // cout << nums.size();
    return nums;
}

int main(){
    // cout << "Test1\n";
    vector<vector<int>> nums = generate(21);
    for (int i=0; i<nums.size(); i++){
        for (int j=0; j<nums[i].size(); j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}