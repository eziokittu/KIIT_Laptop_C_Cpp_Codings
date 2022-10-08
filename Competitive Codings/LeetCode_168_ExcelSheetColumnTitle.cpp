// LeetCode Problem 168 - Excel Sheet Column Title
// https://leetcode.com/problems/excel-sheet-column-title/

#include <iostream>
using namespace std;

int convertToTitle(int n) {
    string a = "";

    //. getting the max number of iterations required
    int maxLoops = 1, temp=n;
    while (temp>0){
        if ((temp/26) == 0 && (temp-1)/26 == 0) break;
        else maxLoops+=1;
        temp/=26;
    }
    // for (int i=26; i>=1; i--){

    // }

    // return a;
    return maxLoops;
}

int main(){
    cout << convertToTitle(1) << " ";
    cout << convertToTitle(25) << " ";
    cout << convertToTitle(26) << " ";
    cout << convertToTitle(27) << " ";
    cout << convertToTitle(26*26-1) << " ";
    cout << convertToTitle(26*27) << " ";
    cout << convertToTitle(26*26*28) << " ";

    return 0;
}

// 27 = 26*1 + 1  == AA
// 52 = 26*1 + 26 == AZ
// 53 = 26*2 + 1  == BA
// 78 = 26*2 + 26 == BZ
// 702 = 26*26 + 26 == ZZ
// 677 = 26*26 + 1 == ZA
// 676 = 26*25 + 26 == YZ
// 703  = 26*26*1 + 26*1 + 1 == AAA  ---------------- this works
// general ----
// (26*26*....*26 maxLoops-1 times )*1 + (26*26*....*26 maxLoops-2 times )*1 ..... = AAAA....

// 2000/26 = 76.92307692 /26 =~ 3
//