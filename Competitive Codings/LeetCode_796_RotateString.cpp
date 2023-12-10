// LeetCode Problem 796 - Rotate String
// https://leetcode.com/problems/rotate-string/description/
#include <iostream>
#include <vector>
using namespace std;

bool rotateString(string s1, string s2) {
    s2 += s2;
    int x = s2.find(s1);
    if (x==-1) return false;
    string temp="";
    for(int i=x+s1.size(); i<s2.size(); i++){
        temp += s2[i];
    }
    for (int i=0; i<x; i++){
        temp += s2[i];
    }
    return (temp==s1);
}

int main() {
    string s1 = "abcde", s2 = "cdeab";
    cout << rotateString(s1, s2);
}