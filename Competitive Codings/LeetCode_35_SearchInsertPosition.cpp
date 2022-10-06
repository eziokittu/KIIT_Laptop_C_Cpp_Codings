// LeetCode Problem 35 - Search Insert Position
// https://leetcode.com/problems/search-insert-position/

#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int pos=-1;
    int start=0, end=nums.size()-1;
    while (start<=end){
        int mid = (start+end)/2;
        if (nums[mid]==target) return mid;
        else if (nums[mid]<target) start = mid+1;
        else if (nums[mid]>target) end = mid-1;

        if (start>=end) pos = start;
    }
    if (nums[pos]<target) return pos+1;
    else if (nums[pos]>target) return pos;
}

int main(){
    vector<int> nums = {0,1,2,3,4,5,7,22,33,44,55,66,77,88,99};
    cout << searchInsert(nums, 8) << endl;
    cout << searchInsert(nums, 25) << endl;
    cout << searchInsert(nums, 45) << endl;
    cout << searchInsert(nums, 97) << endl;
    cout << searchInsert(nums, 100) << endl;
    cout << searchInsert(nums, -599) << endl;
    cout << searchInsert(nums, 2) << endl;
}