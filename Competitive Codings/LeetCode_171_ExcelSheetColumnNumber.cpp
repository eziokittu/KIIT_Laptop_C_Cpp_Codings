// LeetCode Problem - 171 - Excel Sheet Column Number
// https://leetcode.com/problems/excel-sheet-column-number/

#include <iostream>

using namespace std;

int titleToNumber(string s) {
    int num=0;
    for (int i=0; s[i]!='\0'; i++){
        num = num*26 + (int(s[i]-'A')+1);
    }
    return num;
}

int main(){
    cout << titleToNumber("AAA") << endl;
    cout << titleToNumber("ZZZ") << endl;
    cout << titleToNumber("ABC") << endl;
    cout << titleToNumber("Z") << endl;
    return 0;
}