// LeetCode Problem 81 - Search in rotated Sorted Array 2
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>

using namespace std;

void GetSortedArray(vector<int> &nums){
    int index=0;
    for (int i=1; i<nums.size(); i++){
        if (nums[index] > nums[i]){
            break;
        }
        index++;
    }
    vector<int> temp;
    for (int i=index+1; i<nums.size(); i++){
        temp.push_back(nums[i]);
    }
    for (int i=0; i<=index; i++){
        temp.push_back(nums[i]);
    }
    nums = temp;
}

bool search(vector<int>& nums, int target) {
    if (nums.size()==1 && nums[0]==target){
        return true;
    }
    cout << "\nBefore Sorting the array: ";
    for (int i=0; i<nums.size(); i++){
        cout << nums[i]<< " ";
    }
    GetSortedArray(nums);
    cout << "\nAfter Sorting the array: ";
    for (int i=0; i<nums.size(); i++){
        cout << nums[i]<< " ";
    }

    int start = 0, end = nums.size()-1;
    int mid;
    while (start <= end){
        mid = (start + end) / 2;
        if (nums[mid] == target){
            return true;
        }
        else if (nums[mid] < target){
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    return false;
}

int main(){
    vector<int> nums1 = {1,0,1,1,1};
    vector<int> nums2 = {2,5,6,0,0,1,2};
    vector<int> nums3 = {2,2,2,3,2,2,2};
    cout << (search(nums1, 0)==1 ? "true" : "false") << endl;
    cout << (search(nums2, 0)==1 ? "true" : "false") << endl;
    cout << (search(nums3, 3)==1 ? "true" : "false") << endl;
}