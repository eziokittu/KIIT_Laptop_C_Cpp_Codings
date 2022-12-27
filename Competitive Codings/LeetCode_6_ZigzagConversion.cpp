// LeetCode Problem 6 - Zigzag Conversion
// https://leetcode.com/problems/zigzag-conversion/

// INCOMPLETE

#include <iostream>
using namespace std;

string convert(string s, int n) {
    string temp = "";
    int k = (s.length()-1)*2;

    // iterating n times
    for (int i=0; i<n; i++){
        // storing the letters row wise
        int m=0;
        bool running = true;
        while (running) {
            try{
                temp += s[(m*k)+i];
                if (i!=0 && s[(m*k)-i] >= 0){
                    temp += s[(m*k)-i];
                }
                m++;
            }
            catch(exception e){
                cout << "\nRow "<<i<< " Complete!";
                running = false;
            }
        }
    }
    return temp;
    // order for storing the elements
    // for n = 4
    // 0, 6, 12, ....           row 1
    // 1, 5, 7, 11, 13, ....    row 2
    // 2, 4, 8, 10, 14, ....    row 3
    // 3, 9, 15, ....           row 4
}

int main(){
    string s = "TomAndJerry";
    cout << convert(s, 3);
}