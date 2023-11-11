// LeetCode Problem 2423 - Remove Letter to Equalize Frequency
// https://leetcode.com/problems/remove-letter-to-equalize-frequency/description/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool equalFrequency(string word) {
    map<char, int> m;
    for (char i: word){
        m[i]++;
    }
    if (m.size()==1)return true;
    int count_r=0, count_s=0;
    int r=-100, s=-100;
    for (auto i=m.begin(); i!=m.end(); i++){
        
        if (r==-100){
            r = i->second;
            count_r++;
        }
        else if (s==-100 && i->second!=r){
            s = i->second;
            count_s++;
        }
        else {
            int t = i->second;
            if (t==r){
                count_r++;
            }
            else if (t==s){
                count_s++;
            }
            if (t!=r && t!=s){
                cout <<"i->first = "<<i->first<<", t = "<<t<<", r = "<<r<<", s = "<<s<<endl;
                return false;
            }
            if (count_r>1 && count_s>1){
                return false;
            }
        }
        cout <<"r = "<<r<<", s = "<<s<<endl;
    }
    
    if (s==-100 || m.size()==2){
        for (auto i=m.begin(); i!=m.end(); i++){
            if (i->second==1){
                return true;
            }
        }
        if (r-s==1 || s-r==1)
            return true;
    }
    if ((r>s && count_r>1) || (s>r && count_s>1)){
        return false;
    }
    else if (r-s==1 || s-r==1){
        return true;
    }
    return false;
}

int main() {
    // cout << (equalFrequency("bbac")==0 ? "false" : "true")<<endl<<endl;
    // cout << (equalFrequency("abc")==0 ? "false" : "true")<<endl<<endl;
    // cout << (equalFrequency("aabbcc")==0 ? "false" : "true")<<endl<<endl;
    // cout << (equalFrequency("aabbbcdddd")==0 ? "false" : "true")<<endl<<endl;
    // cout << (equalFrequency("zz")==0 ? "false" : "true")<<endl<<endl;
    // cout << (equalFrequency("cccdd")==0 ? "false" : "true")<<endl<<endl;
    cout << (equalFrequency("abbcc")==0 ? "false" : "true")<<endl<<endl;
    // cout << (equalFrequency("ddddbbbbccc")==0 ? "false" : "true")<<endl<<endl;
}