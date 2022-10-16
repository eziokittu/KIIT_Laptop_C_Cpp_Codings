// LeetCode Problem 486 - Predict The winner
// https://leetcode.com/problems/predict-the-winner/

#include <iostream>
#include <vector>

using namespace std;

int score1, score2;

// algo for optimal selection of turn by any player
int WhatToSelect(vector<int> &nums){

    int first, last, valueToReturn;
    // when array length is less than 4
    if (nums.size()<4){
        first = nums[0];
        last = nums[nums.size()-1];
        if (first < last) {
            valueToReturn = last;
            nums.erase(nums.end());
        }
        else {
            valueToReturn = first;
            nums.erase(nums.begin());
        }
    }
    // when array length is 4 or more
    else if (nums.size()>=4){
        int first_next = nums[1], last_previous = nums[nums.size()-1];
        if (first + first_next > last + last_previous){
            valueToReturn = last;
            nums.erase(nums.end());
        }
        else{
            valueToReturn = first;
            nums.erase(nums.begin());
        }
    }

    return valueToReturn;
}

bool PredictTheWinner(vector<int>& nums) {
    
    bool player1Won = false;

    // iterating the array and getting the score for each player
    for (int i=0; i<nums.size()-1; i++){

        // even iterations are for player 1 --- 0, 2, 4, 6, ...
        if (i%2==0){
            score1 += WhatToSelect(nums);
        }

        // odd iterations are for player 2 --- 1, 3, 5, 7, ...
        else if (i%2==1){
            score2 += WhatToSelect(nums);
        }
    }

    if (score1 > score2) player1Won = true;

    return player1Won;
}

int main(){
    // vector<int> nums = {1,2,3,10,5,7,9,4};
    vector<int> nums = {2,4,55,6,8};

    cout <<endl<< PredictTheWinner(nums);
}

/*
1 5 233 7 
0 1 2 3

possible indexes - 8
0123
0132
0312
0321
3012
3021
3201
3210
p1 p2 p1 p2
*/