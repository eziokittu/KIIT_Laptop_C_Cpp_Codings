// LeetCode Problem 38 - Count And Say
// https://leetcode.com/problems/count-and-say/
#include <iostream>

using namespace std;

string getStringFromPrevious(string s){
    string str="";
    char chr=s[0];
    int count = 1;
    for (int i=1; i<s.size(); i++){
        if (chr==s[i]){
            count++;
        }
        else{
            str+='0'+count;
            str+=(char)chr;
            chr=s[i];
            count=1;
        }
    }
    str+='0'+count;
    str+=(char)chr;
    return str;
}

string countAndSay(int n) {
    if (n==1)return "1";
    return getStringFromPrevious(countAndSay(n-1));
}

int main()
{
    cout<<countAndSay(1)<<endl;
    cout<<countAndSay(2)<<endl;
    cout<<countAndSay(3)<<endl;
    cout<<countAndSay(6)<<endl;
    cout<<countAndSay(10)<<endl;
    cout<<countAndSay(20)<<endl;
    cout<<countAndSay(50)<<endl;

    return 0;
}