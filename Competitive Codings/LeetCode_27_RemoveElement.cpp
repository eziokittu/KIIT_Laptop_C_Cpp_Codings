// Leetcode Problem 27 - Remove Element
// https://leetcode.com/problems/remove-element/

// NOT COMPLETED

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int sizeToDeduct=0;
    for (int i=0; i<nums.size(); i++){
        if (nums[i]==val){
            int k=0;
            while (nums[i+k+1]==val){
                k++;
            }
            for (int j=i; j<nums.size()-1; j++){
                nums[j]=nums[j+1+k];
            }   
            i += k; 
            sizeToDeduct += 1;   
        }
    }
    return nums.size()-sizeToDeduct-2;
}

int main(){
    // vector<int> nums = {1,2,2,2,3,4,5,2,1,2,1,7,8,9,13,11,2,18};
    vector<int> nums = {1,1,1,1,1,1,1,2,11,1,2,1,1,1,2,1,1,1,2,11,1};
    // vector<int> nums = {1,2,3,4,5,6,7,8,9,0};

    cout << "\nBefore ---\n";
    for (int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }

    // int sizeAfter = removeElement(nums, 2);
    int sizeAfter = removeElement(nums, 1);
    // int sizeAfter = removeElement(nums, 5);
    cout <<"\nsize = "<< sizeAfter << endl;

    cout << "\nAfter ---\n";
    for (int i=0; i<sizeAfter; i++){
        cout << nums[i] << " ";
    }
}