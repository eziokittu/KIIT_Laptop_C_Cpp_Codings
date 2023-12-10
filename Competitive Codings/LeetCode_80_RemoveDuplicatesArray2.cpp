// LeetCode Problem 80 - Remove Duplicates from Sorted Array 2
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int temp=nums[0];
    int count = 1;
    for (int i=1; i<nums.size(); ){
        if (temp==nums[i]){
            if (count<2){
                count++;
                i++;
            }
            else{
                nums.erase (nums.begin()+i);
            }
        }
        else {
            temp = nums[i];
            count = 1;
            i++;
        }
    }
    return nums.size();
}

int main(){
    vector<int> v = {0,0,0,1,1,1,2,2,3,3,3,3,4,5,6,7,8,8,8,8,9};
    cout << removeDuplicates(v);
    return 0;
}