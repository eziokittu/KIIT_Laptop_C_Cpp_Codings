#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// #define INT32_MAX 2147483647

// Problem - Largest Rectangle area in an Histogram --
// Given an array. Each element represents the height to the
// histogram's bar and the width of each bar is 1.
// Find the area of the largest reactanle in the histogram.

// Approach 1 - Brute Force
int GetLargestArea_BruteForce(vector<int> nums){
  int ans = 0;
  int n = nums.size();
  for (int i=0; i<n; i++){
    int min_height = INT32_MAX;
    for (int j=i; j<n; j++){
      min_height = min(nums[j], min_height);
      int width = j-i+1;
      ans = max(ans, width * min_height);
    }
  }
  return ans;
}

// Approach 2 - Using Stacks
int GetLargestArea_UsingStacks(vector<int> a){
  int n = a.size();
  int ans=0, i=0;
  a.push_back(0);
  stack<int> st;
  while(i<n){
    while (!st.empty() && a[st.top()] > a[i]){
      int t = st.top();
      int h = a[t];
      st.pop();
      if (st.empty()) {
        ans = max(ans, h*i);
      }
      else {
        int len = i - st.top() - 1;
        ans = max(ans, h * len);
      }
    }
    st.push(i);
    i++;
  }
  return ans;
}

int main() {
  vector<int> arr = {1,2,3,4,5,2,5,1};
  // int ans = GetLargestArea_BruteForce(arr);
  int ans = GetLargestArea_UsingStacks(arr);
  cout << "The largest area is '" << ans << "' unit square.";
}