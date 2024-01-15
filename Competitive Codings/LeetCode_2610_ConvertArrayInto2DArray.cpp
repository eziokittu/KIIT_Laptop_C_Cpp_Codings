// LeetCode Problem 2610 - Convert an array into 2d Array with conditions
// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-01

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> findMatrix(vector<int>& nums) {
  unordered_map<int, vector<int>> m;
  m[0]={};
  int start=0;
  for (int i : nums){
    int j = start;
    while (find(m[j].begin(), m[j].end(), i) != m[j].end()){
        j++;
    }
    m[j].push_back(i);
  }
  vector<vector<int>> ans;
  for (const auto& i : m) {
    ans.push_back(i.second);
  }
  return ans;
}

int main() {
  vector<int> nums = {1,2,3,4,1,3,2,4,1};
  vector<vector<int>> ans = findMatrix(nums);
  for (auto i : ans){
    for (auto j : i){
      cout << j<< " ";
    }
    cout << endl;
  }
}