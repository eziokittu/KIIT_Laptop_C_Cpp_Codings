// LeetCode Problem 3 - Longest Substring without repeating characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s==""){
        return 0;
    }

    // cout << endl << "For String '" << s << "' - ";

    vector<int> nums;
    for (int i=0; s[i]!='\0'; i++){
        int len=1;
        for (int j=i+1; s[j]!='\0'; j++){
            if (s[i]==s[j]){
                break;
            }
            else {
                // cout << "-?"<<s[j];
                len++;
            }
        }
        nums.push_back(len);
        // cout <<nums[nums.size()-1];
    }
}

int main(){
    cout << lengthOfLongestSubstring("au")<<endl;          // 2
    cout << lengthOfLongestSubstring("pwwkew")<<endl;      // 3
    // cout << lengthOfLongestSubstring("aaaa")<<endl;     // 1
    // cout << lengthOfLongestSubstring("auabu")<<endl;    // 3
    // cout << lengthOfLongestSubstring("abcabcbb")<<endl; // 3
    // cout << lengthOfLongestSubstring("cdd")<<endl;      // 2
    // cout << lengthOfLongestSubstring("cd")<<endl;       // 2
    return 0;
    // abccccbacd 8611134321
}