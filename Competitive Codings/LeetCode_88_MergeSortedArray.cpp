// LeetCode Problem 88 - Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/

// NOT COMPLETED

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i=0; i<nums2.size(); i++){
        nums1.pop_back();
    }
    for (int i=0; i<nums2.size(); i++){
        nums1.push_back(nums2[i]);
    }

    // cout << "\nPrinting vector array -\n";
    // for (int i=0; i<nums1.size(); i++){
    //     cout << nums1[i] << " ";
    // }

    // sort
    for (int i=0; i<nums1.size()-1; i++){
        for (int j=i+1; j<nums1.size(); j++){
            if (nums1[i] > nums1[j]){
                nums1[i] = nums1[i] + nums1[j];
                nums1[j] = nums1[i] - nums1[j];
                nums1[i] = nums1[i] - nums1[j];
            }
        }
    }
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    merge(nums1, nums1.size(), nums2, nums2.size());

    cout << "\nPrinting vector array -\n";
    for (int i=0; i<nums1.size(); i++){
        cout << nums1[i] << " ";
    }
}