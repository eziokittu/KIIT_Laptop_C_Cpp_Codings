// LeetCode Problem 10 - Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/

#include <iostream>
#include <vector>

using namespace std;

bool isValid(string s, vector<vector<char>>& possible, int i, int state){
    while (i<s.size()){
        // states out of bounds but string s still continues
        if (state>=possible.size()){
            return false;
        }
        // when the single character must be present
        if (possible[state][1]=='1'){
            if (possible[state][0]==s[i] || possible[state][0]=='.'){
                state++;
                i++;
            } 
            else{
                return false;
            }
        }
        // when the character has any length and may not be present
        else if (possible[state][1]=='*'){
            // in the form a* and string matches
            if (possible[state][0]==s[i] && possible[state][0]!='.'){
                i++;
            }
            // in the form .*
            // else if (possible[state][0]=='.'){
                // not sure what to do - will get very length
                // i++;
                // state++;
                // return isValid(s, possible, i, state);
                // state++;
                // return isSpecialValid(s, possible, i, state);
            // }
            // in the form a* but s does not match so proceed to next state
            else if (possible[state][0]!=s[i]){
                state++;
            }
        }
    }
    return true;
}

bool isMatch(string s, string p) {
    vector<vector<char>> possible; // gathering all character and their occurences in p
    int i=0;
    while (i<p.size()){
        if (p[i]=='.'){
            char ch = '.';
            char num = '1'; // only 1 character
            if (p[i+1]=='*'){
                num = '*'; // all length possible including nothing(null)
                i+=2;
            }
            else{
                i++;
            }
            possible.push_back({ch, num});
        }
        else if (p[i]-'a'>=0 && p[i]-'a'<26){
            char ch = p[i];
            char num = '1'; // only 1 character
            if (p[i+1]=='*'){
                num = '*';
                i+=2;
            }
            else{
                i++;
            }
            possible.push_back({ch, num});
        }
    }  

    vector<vector<char>> myString; // gathering all character and their occurences in s
    i=0;
    while (i<s.size()){
        if (s[i]=='.'){
            char ch = '.';
            char num = '1'; // only 1 character
            if (s[i+1]=='*'){
                num = '*'; // all length possible including nothing(null)
                i+=2;
            }
            else{
                i++;
            }
            possible.push_back({ch, num});
        }
        else if (s[i]-'a'>=0 && s[i]-'a'<26){
            char ch = s[i];
            char num = '1'; // only 1 character
            if (s[i+1]=='*'){
                num = '*';
                i+=2;
            }
            else{
                i++;
            }
            possible.push_back({ch, num});
        }
    }  

    // printing
    // for (auto i : possible){
    //     cout << i[0] << " "<<i[1]<<endl;
    // }
    // cout << "\n";
    // for (auto i : myString){
    //     cout << i[0] << " "<<i[1]<<endl;
    // }
    // cout << "\n";
    bool hasSpecial = false;
    for (auto i : possible){
        if ((i[0]=='.') && (i[1]=='*')){
            hasSpecial = true;
        }
    }

    if (hasSpecial==false) {
        return isValid(s, possible, 0, 0);
    }
    
    for (int i=0; i<possible.size();){
        if ((possible[i][0]=='.') && (possible[i][1]=='*')){
            possible.erase(possible.begin()+i);
        }
        else i++;
    }
    return false;
}

int main(){
    cout << isMatch("abccd", "aa*b*ccd*");
    // cout << isMatch("aa", "ab*a");
    // cout << isMatch("aa", "a");
    // cout << isMatch("aa", "ab*.");

    // special case
    // cout << isMatch("aabcdefghadcabcd", ".*ab*dc*a.*"); 
    cout << isMatch("abcac", ".*ca");// a1 b1 c1 a1 c1 - .2 c1 a1
    return 0;
}