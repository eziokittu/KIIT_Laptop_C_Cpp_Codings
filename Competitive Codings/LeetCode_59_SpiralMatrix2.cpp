// LeetCode Problem 59 - Spiral Matrix 2
// 

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int rows = n;
    int cols = n;
    int value = 1;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int i=0;
    while (rows-(2*i)>1 && cols-(2*i)>1){
      if (i<rows-i){
        ans[i][i] = value++;
      }
      for (int j=i+1; j<cols-i; j++){
        ans[i][j] = value++;
      }
      for (int j=i+1; j<rows-i; j++){
        ans[j][cols-1-i] = value++;
      }
      for (int j=cols-2-i; j>=0+i; j--){
        ans[rows-1-i][j] = value++;
      }
      for (int j=rows-2-i; j>0+i; j--){
        ans[j][i] = value++;
      }
      i++;
    }

    if ((rows-(2*i)>0 && cols-(2*i)>0)){
      if (rows-(2*i) >= cols-(2*i)){
        for (int j=i; j<rows-i; j++){
          ans[j][cols-1-i] = value++;
        }
      }
    else if (rows-(2*i) < cols-(2*i)) {
      for (int j=i; j<cols-i; j++){
        ans[i][j] = value++;
      }
    }
  }

  return ans;
}

int main() {
  vector<vector<int>> ans = generateMatrix(7);
  for (auto i : ans){
    for (auto j : i){
      cout << j << " ";
    }
    cout << "\n";
  }
}