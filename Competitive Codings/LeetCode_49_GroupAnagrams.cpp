// LeetCode Problem 49 - Group Anagrams
// https://leetcode.com/problems/group-anagrams/
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

string getCode(string s){
    string n="";
    sort(s.begin(), s.end());
    // sort(begin(s), end(s));
    for (char c : s){
        n+=to_string((int)c);
    }
    return n;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> v;
    map<string, vector<string>> m;
    for (auto str : strs){
        string temp = str;
        m[getCode(temp)].push_back(str);
    }
    for (auto i : m){
        v.push_back(i.second);
    }
    return v;
}
    
int main(){
    vector<string> strs = {{"tea"},{"eat"},{"ate"},{"mug"},{"gum"},{"ball"}};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (auto str : ans){
        for (auto i : str){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}