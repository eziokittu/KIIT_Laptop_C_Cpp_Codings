// LeetCode problem 535 - Encode and Decode TinyURL
// https://leetcode.com/problems/encode-and-decode-tinyurl/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string common = "https://";

string strToBinary(string s)
{
    int n = s.length();
    string str = "";
 
    for (int i = 0; i <= n; i++)
    {
        // convert each char to
        // ASCII value
        int val = int(s[i]);
 
        // Convert ASCII value to binary
        string bin = "";
        while (val > 0)
        {
            (val % 2)? bin.push_back('1') :
                       bin.push_back('0');
            val /= 2;
        }
        reverse(bin.begin(), bin.end());
 
        str+=bin;
    }
    return str;
}

string convert_binToDec(string num)
{
    string decimal="";
}

// Encodes a URL to a shortened URL.
string encode(string longUrl) {
    string s="";
    for (int i=8; i<longUrl.size(); i++){
        s+=longUrl[i];
    }
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl) {
    
}

int main(){
    string url = "https://leetcode.com/problems/design-tinyurl/";
    // for (int i=8; i<url.size(); i++){
    //     cout << (int)url[i]-97;
    //     if (url[i]=='/'){
    //         cout<<endl;
    //     }
    //     else{
    //         cout <<" ";
    //     }
    // }
    // cout << decode(encode(url));
    string s = "geeks";
    cout << strToBinary(s)<<endl;
    cout << getDecimal(10000111111111111111111111);
}