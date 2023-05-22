// Leetcode Problem 4 - Median of 2 sorted arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    for (int i=0; i<nums2.size(); i++){
        nums1.push_back(nums2[i]);
    }

    cout << "\nPrinting vector array -\n";
    for (int i=0; i<nums1.size(); i++){
        cout << nums1[i] << " ";
    }

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
    if (nums1.size()%2==0){
        double a = nums1[nums1.size()/2 - 1];
        double b = nums1[nums1.size()/2];
        return (a+b)/2.0;
    }
    return nums1[nums1.size()/2];
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    cout << findMedianSortedArrays(nums1, nums2);

    cout << "\nPrinting vector array -\n";
    for (int i=0; i<nums1.size(); i++){
        cout << nums1[i] << " ";
    }
}