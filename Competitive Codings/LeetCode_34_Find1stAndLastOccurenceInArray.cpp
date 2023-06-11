// LeetCode Problem 34 - Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result;
    for (int i=0; i<nums.size(); i++){
        if (nums[i]==target){
            result.push_back(i);
            break;
        }
    }
    if (result.size()==0){
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
    for (int i=nums.size()-1; i>=0; i--){
        if (nums[i]==target){
            result.push_back(i);
            break;
        }
    }
    return result;
}

int main(){
    vector<int> arr = {1,2,1,1,3,2,1,2,1,1,3,3,1,3,3,3,2,1,3,1,3,3,2,1,3,2,1,};
    vector<int> m = searchRange(arr, 3);
    cout <<m[0]<<", "<<m[1];
}