// LeetCode Problem - 15 - Three Sum
// https://leetcode.com/problems/3sum/

// Code works but leetcode says time limit exceeded;

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> s;
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            for(int k=j+1; k<nums.size(); k++){
                bool isDistinct = true;

                // checking for duplicate
                for(int l=0; l<s.size(); l++){
                    if ((nums[i]==s[l][0] && nums[j]==s[l][1] && nums[k]==s[l][2]) ||
                        (nums[i]==s[l][0] && nums[j]==s[l][2] && nums[k]==s[l][1]) ||
                        (nums[i]==s[l][1] && nums[j]==s[l][0] && nums[k]==s[l][2]) ||
                        (nums[i]==s[l][1] && nums[j]==s[l][2] && nums[k]==s[l][0]) ||
                        (nums[i]==s[l][2] && nums[j]==s[l][1] && nums[k]==s[l][0]) ||
                        (nums[i]==s[l][2] && nums[j]==s[l][0] && nums[k]==s[l][1])){
                        isDistinct = false;
                    }
                }

                // pushing the numbers in nums vector
                if ((nums[i]+nums[j]+nums[k]) == 0 && (isDistinct==true)){
                    s.push_back(vector<int>{nums[i],nums[j],nums[k]});
                }
            }
        }
    }
    return s;
}

int main()
{
    // vector<int> nums{-1,0,1,2,-1,-4};
    vector<int> nums{12,5,-12,4,-11,11,2,7,2,-5,-14,-3,-3,3,2,-10,9,-15,2,14,-3,-15,-3,-14,-1,-7,11,-4,-11,12,-15,-14,2,10,-2,-1,6,7,13,-15,-13,6,-10,-9,-14,7,-12,3,-1,5,2,11,6,14,12,-10,14,0,-7,11,-10,-7,4,-1,-12,-13,13,1,9,3,1,3,-5,6,9,-4,-2,5,14,12,-5,-6,1,8,-15,-10,5,-15,-2,5,3,3,13,-8,-13,8,-5,8,-6,11,-12,3,0,-2,-6,-14,2,0,6,1,-11,9,2,-3,-6,3,3,-15,-5,-14,5,13,-4,-4,-10,-10,11};
    vector<vector<int>> s = threeSum(nums);
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<s[i].size(); j++){
            printf("%4d ", s[i][j]);
        }
        cout<<endl;
    }

    return 0;
}