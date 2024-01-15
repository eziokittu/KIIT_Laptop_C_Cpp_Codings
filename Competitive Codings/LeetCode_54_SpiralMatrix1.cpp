// LeetCode Problem 54 - Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/description/

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& m) {
  int rows = m.size();
  int cols = m[0].size();
  vector<int> ans;
  int i=0;
  while (rows-(2*i)>1 && cols-(2*i)>1){
    if (i<rows-i){
      ans.push_back(m[i][i]);
    }
    for (int j=i+1; j<cols-i; j++){
      ans.push_back(m[i][j]);
    }
    for (int j=i+1; j<rows-i; j++){
      ans.push_back(m[j][cols-1-i]);
    }
    for (int j=cols-2-i; j>=0+i; j--){
      ans.push_back(m[rows-1-i][j]);
    }
    for (int j=rows-2-i; j>0+i; j--){
      ans.push_back(m[j][i]);
    }
    i++;
  }

  if ((rows-(2*i)>0 && cols-(2*i)>0)){
    if (rows-(2*i) >= cols-(2*i)){
      cout <<"LOG1";
      for (int j=i; j<rows-i; j++){
        ans.push_back(m[j][cols-1-i]);
      }
    }
    else if (rows-(2*i) < cols-(2*i)) {
      cout <<"LOG2";
      for (int j=i; j<cols-i; j++){
        ans.push_back(m[i][j]);
      }
    }
  }

  return ans;
}

int main() {
  vector<vector<int>> m1 = {
    {1,2,3}, 
    {4,5,6}, 
    {7,8,9}
  };
  vector<vector<int>> m2 = {
    {1,2,33,44,55}, 
    {3,4,55,66,77}, 
    {5,6,88,99,111}
  };
  for (auto i : m1){
    for (auto j : i){
      cout << j<< "\t";
    }
    cout << endl;
  }
  vector<int> ans = spiralOrder(m1);
  cout<<"\nPrinting ans:\n";
  for (int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }
}