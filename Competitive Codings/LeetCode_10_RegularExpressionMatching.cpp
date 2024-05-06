// LeetCode Problem 10 - Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<char, char>> getStates (string p){
    vector<pair<char, char>> states;
    char temp = '0';
    for (int i=0; i<p.size(); i++){
        if (p[i]=='*'){
            states.push_back({temp, '2'});
            temp = '0';
        }
        else {
            if (temp!='0') {
                states.push_back({temp, '1'});
            }
            temp = p[i];
        }
    }
    if (temp!='0') {
        states.push_back({temp, '1'});
    }
    return states;
}

bool isPossible (string s, vector<pair<char, char>> states, int c, int state){
    if (c==s.size()-1 && state==states.size()-1){
        cout << "DEBUG: "<<c<<" "<<state<<endl;
        return true;
    }
    if (states[state].first=='.' || s[c] == states[state].first){
        bool ret1=false, ret2=false;
        if (c<s.size()-1 && state<states.size()-1){
            ret1 = isPossible(s, states, c+1, state+1);
        }
        if (states[state].second=='2' && c<s.size()-1){
            ret2 = isPossible(s, states, c+1, state);
        }
        cout << "For c = "<<c<<", state = "<<state<< "\n";
        return (ret1 || ret2);
    }
    else if (states[state].second=='2' && states[state].first!=s[c] && state<states.size()-1){
        return isPossible(s, states, c, state+1);
    }
    return false;
}

bool isMatch(string s, string p) {
    vector<pair<char, char>> states = getStates(p);
    for (auto i : states){
        cout << i.first << " " << i.second << "\n";
    }
    cout << endl;
    if (s[s.size()-1] != states[states.size()-1].first && states[states.size()-1].first!='.'){
        return false;
    }
    return isPossible(s, states, 0, 0);
}
    
int main()
{
    cout << isMatch("ab", ".*c");

    return 0;
}
