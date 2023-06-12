// LeetCode Problem 41 - First Missing Positive
// https://leetcode.com/problems/first-missing-positive/
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    set<int> s;
    for (int i=0; i<nums.size(); i++){
        if (nums[i]>0) s.insert(nums[i]);
    }
    set<int >::iterator it;
    for (it=s.begin(); it != s.end() ; it++ ) {
        cout << *it << " ";
    }
    cout << endl;
    it = s.begin();
    int a=*it;
    if (a!=1){
        return 1;
    }
    it++;
    for (; it != s.end() ; it++ ) {
        if (*it-a!=1){
            return a+1;
        }
        else{
            a++;
        }
    }
    return a+1;
}

int main()
{
    vector<int> nums = {-5,-7,100,0,1,2,3,4,5,7,8,9};
    cout << firstMissingPositive(nums)<<endl;
    
    return 0;
}