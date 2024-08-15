#include <iostream>
#include <vector>

using namespace std;

void GetAllPermutations(vector<int> &nums, vector<vector<int>> &ans, int index){
  if (index == nums.size()){
    ans.push_back(nums);
    return;
  }
  for (int i=index; i<nums.size(); i++){
    if (i==0 || nums[i]%nums[i-1]==0){
      // swap(nums[i], nums[index]);
      GetAllPermutations(nums, ans, index+1);
      // swap(nums[i], nums[index]);
    }
  }
}

int main() {
  int n;
  cin>> n;
  vector<int> nums (n);
  for (int i=1; i<=n; i++){
    nums[i-1] = i;
  }
  vector<vector<int>> ans;
  GetAllPermutations(nums, ans, 0);
  cout << "All the permutations are -\n";
  for (auto a : ans){
    for (auto i : a){
      cout << i << " ";
    }
    cout << endl;
  }
}