// LeetCode Problem - 28 - Find index of 1st occurence of string
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <iostream>
#include <string>

using namespace std;

int strStr(string s, string w) {
    int length=0;
    for (int i=0; w[i]!='\0'; i++){
        length++;
    }
    if (length==0){
        return 0;
    }
    for (int i=0; s[i]!='\0'; i++){
        int len=0;
        // cout << i<< " ";
        if (s[i]==w[0]){
            len=1;
            // cout << "s[i]="<<s[i]<<endl;
            int j;
            for (j=1; w[j]!='\0'; j++){
                if (w[j]==s[i+j]){
                    len++;
                }
                else {
                    break;
                }
            }
        }
        if (len == length){
            return i;
        }
    }
    return -1;
}

int main(){
    // cout << strStr("Leetcode", "Leeto")<<endl;
    cout << strStr("abc", "c")<<endl;
    cout << strStr("baabbbbababbbabab", "abbab")<<endl;
    cout << strStr("aaaaaaaab", "aaab")<<endl;

    return 0;
}