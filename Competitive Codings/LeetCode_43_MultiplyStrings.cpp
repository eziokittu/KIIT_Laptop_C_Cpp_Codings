// LeetCode Problem 43 - Multiply Strings
// https://leetcode.com/problems/multiply-strings/
#include <iostream>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
    vector<string> v;
    // multiply
    for (int i=num1.size()-1; i>=0; i--){
        string temp="";
        for (int k=0; k<num1.size()-1-i; k++){
            temp+='0';
        }
        int carry=0;
        for (int j=num2.size()-1; j>=0; j--){
            int mul = (num1[i]-'0')*(num2[j]-'0')+carry;
            temp=(char)((mul%10)+'0')+temp;
            carry=mul/10;
        }
        temp=(char)(carry+'0')+temp;
        v.push_back(temp);
    }
    int l = num1.size()+num2.size();
    for (int i=0; i<v.size(); i++){
        while (v[i].size()<l){
            v[i]='0'+v[i];
        }
        
    }
    cout << "Printing the strings:\n";
    for (auto str : v){
        for (auto c:str){
            cout <<c;
        }
        cout<<endl;
    }
    cout<<"-------------------\n";
    // add all the strings
    int carry=0;
    string result="";
    for (short int i=l-1; i>=0; i--){
        int sum=carry;
        // cout <<"SUM="<<sum<<"~";
        for (short int j=0; j<v.size(); j++){
            sum += (char)((v[j][i])-'0');
        }
        result = (char)((sum%10)+'0')+result;
        carry = sum/10;
        // cout <<"for i="<<i<<", sum="<<sum%10<<", carry="<<sum/10<<"\n";
    }
    // remove '0' in beginning
    short int d=0;
    for (short int i=0; i<result.size(); i++){
        if (result[i]=='0'){
            d++;
        }
        else {
            break;
        }
    }
    result.erase(0, d);
    if (result==""){
        result="0";
    }
    return result;
}

int main()
{
    cout<<multiply("11","11");

    return 0;
}