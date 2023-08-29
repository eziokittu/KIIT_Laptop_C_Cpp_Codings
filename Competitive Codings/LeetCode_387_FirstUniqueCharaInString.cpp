// LeetCode Problem 387 - First Unique Character in a string
// https://leetcode.com/problems/first-unique-character-in-a-string/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int firstUniqChar(string s) {
    map<char, vector<int>> m;
    for (int i=0; s[i]!='\0'; i++){
        m[s[i]].push_back(i);
    }
    int lowest = s.size();
    for (auto i=m.begin(); i!=m.end(); i++){
        vector<int> t = i->second;
        if(t.size()==1){
            if (t[0]<lowest){
                lowest = t[0];
            }
        }
    }
    if (lowest == s.size()){
        lowest = -1;
    }
    return lowest;
}

int main()
{
    cout<<firstUniqChar("acba")<<endl;
    cout<<firstUniqChar("aaaacbaaa")<<endl;
    cout<<firstUniqChar("abcdabcd")<<endl;

    return 0;
}