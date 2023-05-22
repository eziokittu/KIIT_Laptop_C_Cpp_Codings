// LeetCode problem 347 - Top K frequent elements
// https://leetcode.com/problems/top-k-frequent-elements/

#include <iostream>
#include <vector>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<vector<int>> s; // all unique elements
    
    // getting all the unique elements and their frequencies
    for (int i=0; i<nums.size(); i++){
        bool stepComplete = false;
        for (int j=0; j<s.size(); j++){
            if (nums[i]==s[j][0]){
                s[j][1]++;
                stepComplete = true;
                break;
            }
        }
        if (stepComplete==false){
            vector<int> temp = {nums[i], 1};
            s.push_back(temp);
        }
    }

    // sort the new array
    for (int i=0; i<s.size()-1; i++){
        for (int j=i+1; j<s.size(); j++){
            if (s[i][1]>s[j][1]){
                int temp = s[i][1];
                s[i][1] = s[j][1];
                s[j][1] = temp;

                temp = s[i][0];
                s[i][0] = s[j][0];
                s[j][0] = temp;
            }
        }
    }

    int count = 0;
    vector<int> arr;
    for (int i=s.size()-1; i>=0; i--){
        arr.push_back(s[i][0]);
        count++;
        if (count == k){
            break;
        }
    }

    return arr;
}

int main(){
    vector<int> nums = {4,5,6,4,6,4};
    vector<int> s = topKFrequent(nums, 2);

    for (int i=0; i<s.size(); i++){
        cout << s[i] << " ";
    }
    return 0;
}