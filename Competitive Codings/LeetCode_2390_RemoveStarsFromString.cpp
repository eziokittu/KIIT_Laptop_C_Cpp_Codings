// 2390 - Remove stars from string
// https://leetcode.com/problems/removing-stars-from-a-string/description/

#include <iostream>
using namespace std;

string removeStars(string s) {
    // s.erase(end-i,1);
    int end = s.size();
    int count = 0;
    int start = end;
    for (int i=1; i<=s.size(); i++){
        if (s[end-i]=='*'){
            count++;
            start-=2;
        }
        else if (count == 0){
            end--;
            start--;
        }
        else {
            if (count*2 == end-start){
                int extra = (start<0 ? 0-start : 0);
                s.erase((start<0 ? 0 : start), end-start-extra);
                i -= end-start;
                end = start;
                count = 0;
            }
            else{
                start--;
            }
        }
        cout << "\nTesting: s="<<s;
    }
    return s;
}

int main () {
    cout << removeStars("hell*oM***pp*k") << endl; // hepk
}