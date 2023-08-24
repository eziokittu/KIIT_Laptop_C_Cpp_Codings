// LeetCode Problem - 343 - Integer Break
// https://leetcode.com/problems/integer-break/

#include <iostream>
#include <vector>

using namespace std;

int integerBreak(int n) {
    int k = 2;
    int maxProd=1;
    while (k<n){
        vector<int> v;

        // dividing the k elements as equally as possible
        for (int i=0; i<k; i++){
            v.push_back(n/k);
        }
        int remaining = n-((n/k)*(k));
        for (int i=0; i<k && remaining>0; i++){
            v[i]+=1;
            remaining--;
        }

        // finding the product of all the elements
        int prod = 1;
        for (auto i: v){
            prod*=i;
        }

        // updating the maxProduct
        if (maxProd<prod){
            maxProd = prod;
        }
        // exit condition
        else{
            break;
        }
        
        k++;
    }
    return maxProd;
}

int main(){
    int n = 20;
    // int n = 5;
    // int n = 10;
    // int n = 50;
    cout << integerBreak(n);
}