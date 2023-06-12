
// LeetCode Problem 32 - Longest Valid Parenthesis
// 
#include <iostream>
#include <vector>

using namespace std;

int longestValidParentheses(string s) {
    int noOfBraces=0;
    bool justPopped=false;
    vector<int> nums;
    for (int i=0; i<s.size(); i++){
        if (s[i]=='('){
            justPopped=false;
            nums.push_back(0);
            noOfBraces++;
        }
        else if (s[i]==')' && noOfBraces>0){
            if (justPopped==true){
                for (int i=0; i<nums.size(); i++){
                    if (nums[nums.size()-1-i]==0){
                        nums.erase(nums.begin()+nums.size()-1-i);
                        break;
                    }
                }
                // for (auto i:nums){
                //     cout <<i<<" ";
                // }
                // cout<<endl;
            }
            justPopped=true;
            noOfBraces--;
            nums[nums.size()-1]+=2;
        }
        else{
            nums.push_back(0);
        }
    }
    nums.push_back(0);
    // for (auto i:nums){
    //     cout <<i<<" ";
    // }
    // cout<<endl;
    int longest=0, len=0;
    for (int i=0; i<nums.size(); i++){
        if (nums[i]==0){
            if (longest<len){
                longest=len;
            }
            len=0;
        }
        else {
            len+=nums[i];
        }
        // cout<<"i="<<i<<", len="<<len<<endl;
    }
    return longest;
}

int main(){
    cout << endl << longestValidParentheses("(()))))(())()()()()))()((()))");
    cout << endl << longestValidParentheses("()(()");
    return 0;
}