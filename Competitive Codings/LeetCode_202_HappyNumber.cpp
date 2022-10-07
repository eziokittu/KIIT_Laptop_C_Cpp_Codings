// LeetCode Problem 202 - Happy Number
// https://leetcode.com/problems/happy-number/

#include <iostream>
#include <vector>
using namespace std;

int sumIs1(int n, vector<int> &nums){
    // int sum=0;
    // //cout <<"For n="<<n;
    // while (n>0){
    //     sum += (n%10)*(n%10);
    //     n /= 10;
    // }
    // //cout<<", sum="<<sum<<endl;
    // nums.push_back(sum);
    // if (sum==1) return 1;

    // // breaking conditions from the recursion
    // int count=0;
    // if (nums.size()==100) return 0; // 100 is hardcoded, say even after 100 times, sum != 1, SAD
    // for (int i=0; i<nums.size(); i++){
    //     if (sum==nums[i]) count++;
    //     if (count>1) return 0;
    // }

    // // Recursion
    // sumIs1(sum, nums);

    int sum=0;
    while (n>0){
        sum += (n%10)*(n%10);
        n /= 10;
    }
    nums.push_back(sum);
    if (nums.size()==100) return 0;
    int count=0;
    for (int i=0; i<nums.size(); i++){
        if (sum==nums[i]) count++;
        if (count>1) return 0;
    }
    if (sum!=1) return sumIs1(sum, nums);
    return 1;
}

bool isHappy(int n){
    vector<int> nums;
    if (sumIs1(n, nums)==1) return true;
    return false;
}

int main(){
    cout << isHappy(19) << endl;
    cout << isHappy(7) << endl;
    cout << isHappy(13) << endl;
    cout << isHappy(26) << endl;
    cout << isHappy(564) << endl;
    cout << isHappy(1002) << endl;
    cout << isHappy(1) << endl;

    return 0;
}