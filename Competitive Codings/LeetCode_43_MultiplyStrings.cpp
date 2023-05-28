// LeetCode Problem 43 - Multiply Strings
// https://leetcode.com/problems/multiply-strings/

#include <iostream>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    int i=n1-1, j=n2-1, carry=0;
    cout <<n1<<n2;
    vector<string> s;

    while (i>=0){
        string res = "";
        for (j=n2-1; j>=0; j--){
            int mul = (num2[j]-'0')*(num1[i]-'0') + carry;
            carry = mul/10;
            mul = mul%10;
            res = (char)(mul+'0') + res;
        }
        res = (char)(carry+'0') + res;
        s.push_back(res);
        cout << "\nFor i="<<i<<" - "<<res;
        i--;
    }
    return "";
}

int main(){
    cout << multiply("7", "222");
    return 0;
}