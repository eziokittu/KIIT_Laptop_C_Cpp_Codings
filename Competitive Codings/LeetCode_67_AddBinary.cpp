// LeetCode Problem - 67
// https://leetcode.com/problems/add-binary/

#include <iostream>
using namespace std;

// int getValue(string s){
//     int sum=0;
//     for (int i=0; s[i]!='\0'; i++){
//         sum = sum*2 + (int(s[i])-'0');
//     }
//     return sum;
// }

// string addBinary(string a, string b) {
//     string s = "";
//     int len=0;
//     int n = getValue(a) + getValue(b);
//     for (int i=n; i>=0; i=i/2){
//         if (i%2==0){
//             s+='0';
//         }
//         else if (i%2==1){
//             s+='1';
//             i=i-1;
//             if (i==0)
//                 break;
//         }
//         len++;
//     }
//     for (int i=0; i<len/2; i++){
//         char temp = s[i];
//         s[i] = s[len-i];
//         s[len-i] = temp;
//     }
//     return s;
// }

string addBinary(string a, string b) {
    int l1=0, l2=0;
    int c = 0; // carry
    string s = "";
    for (int i=0; a[i]!='\0'; i++)
        l1++;
    for (int i=0; b[i]!='\0'; i++)
        l2++;
    for (int i=l1, j=l2; ;i--, j--){
        int m=0,n=0;
        if (i<=0 && j<=0){ // loop exit condition
            break;
        }
        if (i<=0){
            m = 0;
        }
        else{
            m = int(a[i]);
        }
        if (j<=0){
            n = 0;
        }
        else {
            n = int(b[j]);
        }
        int k = m + n + c - '0';
        switch (k){
            case 0:
                s+='0';
                break;
            case 1:
                s+='1';
                break;
            case 2:
                s+='0';
                c=1;
                break;
            case 3:
                s+='1';
                c=1;
                break;
            default:
                cout << "\nSomething wrong in logic. k="<<k;
                break;
        }  
    }
    return s;
}

int main(){
    cout << "Started\n";
    cout << addBinary("11", "100");
    cout << "\nDone";
    return 0;
}