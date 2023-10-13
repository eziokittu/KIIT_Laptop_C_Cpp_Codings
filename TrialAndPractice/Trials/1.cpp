#include<iostream>
#include<vector>
#include<map>
using namespace std;

int g_count=0; // remove

bool isPalindrome(string s){
    for (int i=0; i<s.size()/2; i++){
        if (s[i]!=s[s.size()-1-i]){
            return false;
        }
    }
    return true;
}

string getlongestPalindrome(string s, map<string, int>& m, int& length) {
    g_count++; // remove from code
    m[s]++;
    if (isPalindrome(s)){
        if (length < s.size()){
            length = s.size();
        }
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
    if (a.size()>length){
        m[a]++;
        if (m[a]==1){
            m[a]=0;
            s1 = getlongestPalindrome(a, m, length);
        }
    }
    
    string s2="";
    if (b.size()>length){
        m[b]++;
        if (m[b]==1){
            m[b]=0;
            s2 = getlongestPalindrome(b, m, length);
        }
    }
    if (s1.size()<s2.size()){
        return s2;
    }
    return s1;
}

string longestPalindrome(string s) {
    map<string, int> m;
    int length=0;
    return getlongestPalindrome(s, m, length);
}

int main(){
    // cout << longestPalindrome("babaddtattarrattatddetartrateedredividerb");
    cout << longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
    cout <<"\nTotal Iterations : "<<g_count; // remove
    return 0;
}