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

// int Fact(int n, int limit){
//     if (n<=limit) return 1;
//     return n*Fact(n-1, limit);
// }

// int Permutation(int n, int r){
//     return ( (Fact(n, n-r)) / (Fact(n-r, 1)) );
// }

// int climbStairs(int n) {
//     int a = n/2; // no of steps of size 2
//     int b = n - (2*a); // no of steps of size 1
//     int ans = 0;
//     while (a>=0){
//         ans += Permutation(a+b, b);
//         a-=1;
//         b+=2;
//     }
//     return ans+1;
// }