#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void permutation(vector<int>& nums, vector<vector<int>>& ans, int idx){
    if (idx == nums.size()){
        ans.push_back(nums);
        return;
    }
    for (int i=idx; i<nums.size(); i++){
        swap(nums[i], nums[idx]);
        permutation(nums, ans, idx+1);
        swap(nums[i], nums[idx]);
    }
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    permutation(nums, ans, 0);
    cout<<"Permutations for the sequence ";
    for (auto i : nums){
        cout<<i<<" ";
    }
    cout<<"are :\n";
    for (auto v:ans){
        for (auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}