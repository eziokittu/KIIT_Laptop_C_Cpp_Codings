// LeetCode Problem 6 - Zigzag Conversion
// https://leetcode.com/problems/zigzag-conversion/

// INCOMPLETE

#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int n) {
    if (n<2) return s;
    vector<string> v;
    for (int i=0; i<n; i++){
        v.push_back("");
    }
    int k=0;
    for (int i=0; i<s.size(); i+=(2*n)-2){ // iterating string
        for (int j=0; j<n-1; j++){ // iterating up to down
            if (k<s.size()){
                v[j]+=s[k++];
            }
        }
        for (int j=n-1; j>0; j--){ // iterating down to up
            if (k<s.size()){
                v[j]+=s[k++];
            }
        }
    }
    string ans = "";
    for (string str : v){
        for (char i : str){
            ans += i;
        }
    }
    return ans;
}

int main(){
    cout << convert("paypalishiring", 3)<<"\n";
    cout << convert("paypalishiring", 4)<<"\n";
    cout << convert("a", 1)<<"\n";
}