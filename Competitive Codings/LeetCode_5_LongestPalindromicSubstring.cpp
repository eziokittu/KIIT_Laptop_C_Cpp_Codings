// LeetCode Problem 5 - Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int g_count;

bool isPalindrome(string s){
    for (int i=0; i<s.size()/2; i++){
        if (s[i]!=s[s.size()-1-i]){
            return false;
        }
    }
    return true;
}

string getlongestPalindrome(string s, map<string, int>& m) {
    g_count++; // remove from code
    m[s]++;
    if (isPalindrome(s)){
        return s;
    }
    string a="",b="";
    for (int i=1; i<s.size(); i++){
        a+=s[i];
    }
    for (int i=0; i<s.size()-1; i++){
        b+=s[i];
    }
    string s1="";
    m[a]++;
    if (m[a]==1){
        m[a]=0;
        s1 = getlongestPalindrome(a,m);
    }
    string s2="";
    m[b]++;
    if (m[b]==1){
        m[b]=0;
        s2 = getlongestPalindrome(b,m);
    }
    if (s1.size()<s2.size()){
        return s2;
    }
    return s1;
}

string longestPalindrome(string s) {
    if (s.size()<2) return s;
    map<string, int> m;
    return getlongestPalindrome(s, m);
}

int main(){
    // cout << longestPalindrome("babaddtattarrattatddetartrateedredividerb");
    cout << longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
    cout <<"\nTotal Iterations : "<<g_count; // remove
    return 0;
}