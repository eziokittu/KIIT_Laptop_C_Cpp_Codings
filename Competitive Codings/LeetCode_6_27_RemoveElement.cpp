// Leetcode Problem 27 - Remove Element
// https://leetcode.com/problems/remove-element/

// NOT COMPLETED

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    vector<int>::iterator iter;
    iter = remove(nums.begin(), nums.end(), val);
    
    return nums.size();
}

int main(){
    vector<int> nums = {1,2,2,2,3,4,5,2,1,2,1};

    cout << "\nBefore ---\n";
    for (int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }

    removeElement(nums, 2);

    cout << "\nAfter ---\n";
    for (int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
}