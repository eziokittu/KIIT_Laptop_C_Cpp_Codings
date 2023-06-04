// LeetCode problem 535 - Encode and Decode TinyURL
// https://leetcode.com/problems/encode-and-decode-tinyurl/

#include <iostream>
#include <vector>

using namespace std;

string common = "https://";

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
    for (int i=8; i<url.size(); i++){
        cout << (int)url[i]-97;
        if (url[i]=='/'){
            cout<<endl;
        }
        else{
            cout <<" ";
        }
    }
    // cout << decode(encode(url));
}