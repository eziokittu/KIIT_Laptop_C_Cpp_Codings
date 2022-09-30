#include <iostream>
#include <vector>
using namespace std;

void longestCommonPrefix(vector<string>& s) {
    // int i, j, k=0;
    // std::string t = "";
    // char c;
    
    // for (i=0; i<s[0].size(); i++){
    //     // getting the letter
    //     c = s[i][k++];
        
    //     // checking each letter for each word
    //     for (j=0; j<s.size(); j++){
    //         if (s[j][i] == c) t+=c;
    //         else break;
    //     }
    // }
    string t = "";
    char c = s[0][0];
    int k=0, flag = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j=0; s[i][j]!='\0' && k<=j; j++){
            if (c==s[i][j]) flag++;
            if (flag != 0) break;
            cout << "-" << c;
        }
        if (flag==0) t+=c;
    }
    cout << t;
}

int main(){
    vector <string> str={"kkkielo","kki","kkktilla"};
    longestCommonPrefix(str);
}