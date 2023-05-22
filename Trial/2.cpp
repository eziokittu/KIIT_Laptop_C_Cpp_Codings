// LeetCode Problem - 1037 - JumpGame III
// https://leetcode.com/problems/jump-game-iii/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

bool canReach(vector<int>& nums, int start, int jump){
    int tries=0;
    int length = start + jump;
    if (length == nums.size()-1){
        return 1;
    }
    else {
        tries = reachedTarget(nums, length, nums[length]);
    }
}

bool canJump(vector<int>& nums, int start) {
    int n = nums.size();
    int x = reachedTarget(nums, 0, nums[0]);
    return x;
}



int main(){
    // vector<int> nums = {3,4,0,1,0,1,2,0,9};
    cout << canJump(nums);
}