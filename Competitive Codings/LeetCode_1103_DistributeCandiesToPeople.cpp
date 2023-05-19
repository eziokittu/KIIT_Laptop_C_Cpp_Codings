// LeetCode Problem 1103 - Distribute Candies to people
// https://leetcode.com/problems/distribute-candies-to-people/

#include <iostream>
#include <vector>
using namespace std;

vector<int> distributeCandies(int c, int n) {
    vector<int> nums;
    for (int i=0; i<n; i++){
        nums.push_back(0);
    }

    int loop=0;
    while (c>0){
        for (int i=0; i<nums.size(); i++){
            int candies = (loop*n)+(i+1);
            if (candies<=c){
                nums[i]+=candies;
                c-=candies;;
            }
            else{
                nums[i]+=c;
                c=0;
            }
            // out of candies
            if (c==0){
                break;
            }
        }
        loop++;
    }
    return nums;
}

int main(){
    vector<int> nums = distributeCandies(100, 8);

    // Displaying
    for (int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
}