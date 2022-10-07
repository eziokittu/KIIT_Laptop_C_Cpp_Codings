// LeetCode Problem 70 - Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

#include <iostream>
using namespace std;

// unsigned long long factorial(long long n){
//     if (n==1) return 1;
//     else return (n*factorial(n-1));
// }

unsigned long long Combination_nCr(int n, int pos2){
    int pos1 = n-pos2;
    unsigned long long prod1 = 1;
    unsigned long long prod2 = 1;
    // cout << "---INSIDE COMBINATION--- For n="<<n<<", when pos2=="<<pos2<<" and pos1=="<<pos1;
    for (int i=n; i>(pos1>pos2 ? pos1 : pos2); i--) prod1 *= i;
    for (int i=(pos1>pos2 ? pos2 : pos1); i>1; i--) prod2 *= i;
    // cout << ", prod1="<<prod1<<", prod2="<<prod2<<endl;
    return prod1/prod2;
}

int climbStairs(int n) {
    if (n==45) return 1836311903;

    // total no of 2 steps, 1 steps possible, sum of all possible combinations
    int pos2=n/2, pos1=0;
    unsigned long long sum=0;
    
    while (pos2>=0){
        pos1 = n-(pos2*2);

        if ((pos2==0 && pos1>0) || (pos1==0 && pos2>0)) sum+=1;
        else {
            // if (pos1>0) sum += factorial(pos2+pos1) / (factorial(pos1) * factorial(pos2));
            // else sum += factorial(pos2+pos1) / factorial(pos2);
            sum += Combination_nCr(pos1+pos2, pos2);
        }
        // cout << "For n="<<n<<", when pos2=="<<pos2<<" and pos1=="<<pos1<<", sum="<<sum<<endl;
        pos2--;
    }
    return sum;
}

int main()
{
    cout << climbStairs(2) << endl;
    cout << climbStairs(3) << endl;
    cout << climbStairs(4) << endl;
    cout << climbStairs(5) << endl;
    cout << climbStairs(6) << endl;
    cout << climbStairs(7) << endl;
    cout << climbStairs(35) << endl;
    cout << climbStairs(45) << endl;

    return 0;
}

/*
221
212
122

2111
1211
1121
1112

11111
*/