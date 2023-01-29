// // LeetCode Problem 557 - Reverse Words In String III
// https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include <iostream>
using namespace std;

// string ExtractWordAndReverse(string s, int start, int end){
//     string rev = "";
//     // Iterating the string from right to left
//     for (int i=end; i>=start; i--){
//         rev += s[i];
//     }

//     return rev;
// }

// string reverseWords(string s) {
//     string rev = "";
//     int start=0, end=0;
//     bool wordCompleted = false;
//     for (int i=0; ; i++){
//         if (s[i]==' ' || s[i]=='\0'){
//             wordCompleted = true;
//         }
//         if (wordCompleted){
//             end=i-1; // end index is INCLUSIVE
//             if (rev=="")
//                 rev = ExtractWordAndReverse(s, start, end);
//             else{
//                 rev = rev + ' ' + ExtractWordAndReverse(s, start, end);
//             }
//             start=i+1; // updating the starting index
//             wordCompleted = false;
//         }
//         if (s[i]=='\0') break;
//     }

//     return rev;
// }

string reverseWords(string s) {
    string word="", rev="";
    int start=0, end=0;
    for (int i=0; ; i++){
        if (s[i]==' ' || s[i]=='\0'){
            end=i-1;
            for (int j=end; j>=start; j--){
                word += s[j];
            }
            if (rev=="")
                rev += word;
            else {
                rev += ' '+word;
            }
            word="";
            start=i+1;
        }

        if (s[i]=='\0')
            break;
    }

    return rev;
}

int main(){
    cout << reverseWords("Hello India Good Morning!");

    return 0;
}