// LeetCode Problem 10 - Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// this section needs change
bool check(string s, map<int, vector<int>> &m, int i, int j){
    if (s.size()==i && m.size()==j){
        return true;
    }
    if (m[j][1]==-1){
        j++;
    }
    if (s[i] == (char)m[j][0]){
        if (m[j][1]>1){
            m[j][1]--;
        }
        else if (m[j][1]==1){
            m[j][1]=-1; // deleted
        }
        else if (m[j][1]==0){
            check(s, m, i+1, j);
        }
        // never executed
        else{
            return false;
        }
    }
    else {
        if (m[j][1]==0){
            return check(s, m, i+1, j+1);
        }
        else {
            return false;
        }
    }
    return true;
}

// this section of code is good
bool isMatch(string s, string p) {
    map<int, vector<int>> m;
    int k=0;
    char temp=p[0];
    m[k]={temp, 1};
    for (int i=1; i<p.size(); i++){
        if (p[i]==temp){
            m[k][1]++;
        }
        else {
            if (p[i]=='*'){
                if (m[k][1]>1){
                    m[k][1]--;
                    m[++k] = {temp, 0};
                    continue;
                }
                m[k][1]=0; // 0 represented as *
                continue;
            }
            temp = p[i];
            m[++k]={temp, 1};
        }
    }
    cout << "\nPrinting the Language:\n";
    for (auto i=m.begin(); i!=m.end(); i++){
        cout << i->first<<": "<<(char)i->second[0] << " "<<i->second[1]<<"\n";
    }
    return check(s, m, 0, 0);
}

int main(){
    cout << isMatch("abccd", "aa*b*ccd*");
    cout << isMatch("aa", "a*bbbdb*cda*b.*a");
    // cout << isMatch("aa", "ab*a");
    // cout << isMatch("aa", "a");
    // cout << isMatch("aa", "ab*.");

    // special case
    // cout << isMatch("aabcdefghadcabcd", ".*ab*dc*a.*"); 
    cout << isMatch("abcac", ".*ca");// a1 b1 c1 a1 c1 - .2 c1 a1
    return 0;
}