// LeetCode problem - 125 - Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/

#include <iostream>

using namespace std;

bool isPalindrome(string s) {
    string str = "";
    int len=0;
    for (int i=0; s[i]!='\0'; i++){
        int c = int(s[i]);
        if ((c>96 && c<123) || (c>47 && c<58)){
            str += s[i];
            len++;
        }
        else if (c>64 && c<91){
            str += char(c+32);
            len++;
        }
    }
    // cout << str << ", len="<<len<<endl;
    for (int i=0, j=len-1; i<=j && j>=0; i++, j--){
        // cout << str[i] << " " << str[j] << ", at i="<<i<< ", at j="<<j <<endl;
        if (str[i]!=str[j]){
            return false;
        }
    }
    return true;
}

int main(){
    // cout <<endl<< isPalindrome("\"A man, a plan, a canal: Panama\"");
    cout <<endl<< isPalindrome("race a car");
    cout <<endl<< isPalindrome("A9891089a");
}
// amanaplanacanalpanama