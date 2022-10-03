// LeetCode Problem 69 - My Sqrt
// https://leetcode.com/problems/sqrtx/

#include <iostream>
using namespace std;

int mySqrt(int x) {
        if (x==1) return 1;
        else if (x<2147483648 && x>=2147395600) return 46340;
        for (int i=1; i<=(x/2); i++){
            int sum1 = i*i;
            int sum2 = (i+1)*(i+1);
            if (sum1 <= x && x < sum2) return i;
        }
        return 0;
    }

int main(){
    cout << mySqrt(2147302921);
}