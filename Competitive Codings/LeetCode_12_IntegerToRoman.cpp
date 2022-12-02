// Leetcode problem 12 - Integer to Roman
// https://leetcode.com/problems/integer-to-roman/

#include <iostream>
using namespace std;

string intToRoman(int num) {
    string s = "";

    // for values C, M, D
    while (num/1000>=1 || num>899){
        if (num<1000){
            s += "CM";
            num -= 900;
        }
        else {
            s += "M";
            num -= 1000;
        }
    }
    if (num>399 && num<500){
        s += "CD";
        num -= 400;
    }
    if (num/500==1){
        s += "D";
        num -= 500;
    }

    // for values X, C, L
    while (num/100>=1 || num>89){
        if (num<100){
            s += "XC";
            num -= 90;
        }
        else {
            s += "C";
            num -= 100;
        }
    }
    if (num>39 && num<50){
        s += "XL";
        num -= 40;
    }
    if (num/50==1){
        s += "L";
        num -= 50;
    }

    // for values I, X, V
    while (num/10>=1 || num==9){
        if (num==9){
            s += "IX";
            num -= 9;
        }
        else {
            s += "X";
            num -= 10;
        }
    }
    if (num/5==1){
        s += "V";
        num -= 5;
    }

    // for values I
    while (num/1>=1){
        if (num == 4){
            s += "IV";
            num -= 4;
            break;
        }
        s += "I";
        num -= 1;
    }

    return s;
}

int main(){
    cout << intToRoman(40)<<endl;
    cout << intToRoman(400)<<endl;
    cout << intToRoman(90)<<endl;
    cout << intToRoman(900)<<endl;
    cout << intToRoman(235)<<endl;
    cout << intToRoman(239)<<endl;
    cout << intToRoman(2001)<<endl;

    return 0;
}

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// Input: num = 58
// Output: "LVIII"

// Input: num = 1994
// Output: "MCMXCIV"