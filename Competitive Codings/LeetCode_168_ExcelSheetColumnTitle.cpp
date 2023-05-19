// LeetCode Problem 168 - Excel Sheet Column Title
// https://leetcode.com/problems/excel-sheet-column-title/

#include <iostream>
using namespace std;

string convertToTitle(int num) {
    string s = "";
    while (num>0){
        int quotient = num/26;
        int rem = num - 26*quotient;
        if (rem==0){
            s = 'Z' + s;
            quotient-=1;
        }
        else 
            s=(char)(rem+'A'-1)+s;
        num = quotient;
    }
    return s;
}

int main(){
    cout << convertToTitle(1) <<endl;
    cout << convertToTitle(25) <<endl;
    cout << convertToTitle(26) <<endl;
    cout << convertToTitle(27) <<endl;
    cout << convertToTitle(26*26-1) <<endl;
    cout << convertToTitle(26*27) <<endl;
    cout << convertToTitle(26*26*28) <<endl;

    return 0;
}

