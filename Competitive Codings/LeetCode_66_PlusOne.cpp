// LeetCode Problem 136 - Single Number
// https://leetcode.com/problems/plus-one/

#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& nums) {
    int count=0;
    for (int i=0; i<nums.size(); i++){
        if (nums[i]==9) count++;
        else break;
    }
    if (count==nums.size()){
        nums.insert(nums.begin(),1);
        for (int i=1; i<nums.size(); i++){
            nums[i] = 0;
        }
        return nums;
    }
    else {
        int carry=0;
        for (int i=nums.size()-1; i>=0; i--){
            if (nums[i]==9 && (i==nums.size()-1 || carry==1)){
                nums[i] = 0;
                carry = 1;
            }
            else if (nums[i]<9){
                if (carry==1){
                    nums[i]+=1;
                    carry=0;
                }
                else if (i==nums.size()-1){
                    nums[i]+=1;
                }
                else{
                    break;
                }
            }
        }
        return nums;
    }
}

int main(){
    // vector<int> nums = {8,9,9};
    // vector<int> nums = {1,2,3};
    // vector<int> nums = {9,8,7,6,5,4,3,2,1,0};
    vector<int> nums = {8,8,5,0,5,1,9,7};
    // vector<int> nums = {9};
    // vector<int> nums = {4,6,7,1};
    vector<int> result = plusOne(nums);

    cout << "\nPrinting vector array -\n";
    for (int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
}