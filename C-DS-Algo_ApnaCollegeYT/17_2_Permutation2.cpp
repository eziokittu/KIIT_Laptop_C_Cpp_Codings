#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void helper(vector<int>& a, vector<vector<int>>& ans, int idx){
    if (idx==a.size()){
        ans.push_back(a);
        return;
    }
    for (int i=idx; i<a.size(); i++){
        if (i!=idx && a[i]==a[idx]){
            continue;
        }
        swap(a[i], a[idx]);
        helper(a, ans, idx+1);
    }
}

vector<vector<int>> permutation(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    helper(nums, ans, 0);
    return ans;
}

int main(){
    vector<int> nums = {1,1,2};
    vector<vector<int>> ans = permutation(nums);
    cout<<"are :\n";
    for (auto v:ans){
        for (auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}