// LeetCode Problem 268 - Missing Number
// https://leetcode.com/problems/missing-number/

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int sum=0;
    for (int i=nums.size()-1; i>=0; i--){
        sum+=i;
    }
    return (nums.size()*(nums.size()+1))/2 - sum;

}

int main(){
    vector<int> nums = {0,3,9,2,8,1,5,4,6};

    cout << missingNumber(nums) << endl;;

    return 0;
}