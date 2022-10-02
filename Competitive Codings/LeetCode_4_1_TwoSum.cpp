// Leetcode problem - EASY - 1 - Two Sum
// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result = {};
    for (int i=0; i<nums.size(); i++){
        for (int j=i+1; j<nums.size(); j++){
            if (nums[i] + nums[j] == target){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

int main(){
    vector<int> nums = {2,5,5,7,9,9,9,14};

    for (int i=0; i<2; i++){
        cout << twoSum(nums, 19)[i] << " ";
    }
}