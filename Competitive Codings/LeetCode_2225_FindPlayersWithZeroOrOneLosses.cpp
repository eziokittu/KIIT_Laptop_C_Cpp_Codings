// LeetCode Problem 2225 - Find Players with zero or one losses
// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15

#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
  map<int, int> wins;
  for (auto match : matches){
    // does not exist
    if (wins.find(match[0])==wins.end()){
      wins[match[0]]=2;
    }

    // does not exist
    if (wins.find(match[1]) == wins.end()) {
      wins[match[1]] = 1;  // Initialize with 1 if key does not exist
    } else {
      wins[match[1]] -= 1;  // Decrease by 1 if key exists
    }
  }
  vector<vector<int>> ans = {{},{}};
  for (auto i : wins){
    if (i.second == 2){
      ans[0].push_back(i.first);
    }
    if (i.second == 1){
      ans[1].push_back(i.first);
    }
  }
  return ans;
}

int main() {
  vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
  vector<vector<int>> ans = findWinners(matches);
  for (auto i : ans){
    for (auto j : i){
      cout << j << " ";
    }
    cout << "\n";
  }
}