// LeetCode Problem 136 - Single Number
// https://leetcode.com/problems/single-number/

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    for (int i=0; i<nums.size(); i+=2){
        int count = 1;
        for (int j=i+1; j<nums.size(); j++){
            if (nums[i] == nums[j]) {
                count++;
                nums[j] = nums[i+1];
                break;
            }
        }
        if (count==1) return nums[i];
    }
    return 0;
}

int main(){
    vector<int> nums = {100,200,500,200,400,100,500};
    // vector<int> nums = {2,2,1};
    cout << endl << singleNumber(nums);
}