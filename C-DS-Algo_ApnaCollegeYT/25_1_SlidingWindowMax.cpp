#include <iostream>
#include <deque>
#include <vector>
#include <set>

using namespace std;

// Sliding window maximum problem, with window size given for an array
// Less optimal approach - O(nlog(n))
vector<int> slidingWindowMax_method1(vector<int> nums, int k) {
  multiset<int, greater<int>> s;
  vector<int> ans;
  for (auto i=0; i<k; i++){
    s.insert(nums[i]);
  }
  ans.push_back(*s.begin());

  for (int i=k; i<nums.size(); i++){
    s.erase(s.lower_bound(nums[i-k]));
    s.insert(nums[i]);
    ans.push_back(*s.begin());
  }

  return ans;

  // OUTPUT
  for (auto i : ans){
    cout << i << " ";
  }
}

// Optimal approach - O(n)
// Using Deque data structure
vector<int> slidingWindowMax_method2(vector<int> nums, int k) {
  deque<int> q;
  vector<int> ans;
  for (int i=0; i<k; i++){
    while (!q.empty() && nums[q.back()] < nums[i]) {
      q.pop_back();
    }
    q.push_back(i);
  }
  ans.push_back(nums[q.front()]);
  for (int i=k; i<nums.size(); i++){
    if (q.front() == i-k) {
      q.pop_front();
    }
    while (!q.empty() && nums[q.back()] < nums[i]){
      q.pop_back();
    }
    q.push_back(i);
    ans.push_back(nums[q.front()]);
  }

  return ans;
}

int main() {
  vector<int> nums = {1,-4,-2,-1,0,32,1,-8,-19,-11,5};
  int k = 3;

  // vector<int> ans = slidingWindowMax_method1(nums, k);
  vector<int> ans = slidingWindowMax_method2(nums, k);
  for (auto i : ans){
    cout << i << " ";
  }
}