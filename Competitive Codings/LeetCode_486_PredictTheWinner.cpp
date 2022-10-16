// LeetCode Problem 486 - Predict The winner
// https://leetcode.com/problems/predict-the-winner/

#include <iostream>
#include <vector>

using namespace std;

int score1=0, score2=0;

// algo for optimal selection of turn by any player
int WhatToSelect(vector<int> &nums){
    cout << "\n-------Debug 0------";
    int first = nums[0], last = nums[nums.size()-1], valueToReturn=0;
    // when array length is less than 4
    if (nums.size()<4){
        cout << "\n-------Debug 1------";
        if (first < last) {
            cout << "\n-------Debug 1.1----";
            valueToReturn = last;
            // nums.erase(nums.end());
            nums.erase(nums.begin()+nums.size()-1);
        }
        else {
            cout << "\n-------Debug 1.2----";
            valueToReturn = first;
            nums.erase(nums.begin());
        }
    }
    // when array length is 4 or more
    else if (nums.size()>=4){
        cout << "\n-------Debug 2------";
        int first_next = nums[1], last_previous = nums[nums.size()-2];
        if (first + first_next > last + last_previous){
            cout << "\n-------Debug 2.1----";
            if (first + first_next >= (last + last_previous)*2){
                if (first > first_next){
                    valueToReturn = first;
                    nums.erase(nums.begin());
                }
                else{
                    valueToReturn = last;
                    nums.erase(nums.begin()+nums.size()-1);
                }
            }
            else {
                valueToReturn = last;
                // nums.erase(nums.end());
                nums.erase(nums.begin()+nums.size()-1);
            }
        }

        // when a[0]+a[1] < a[n-1]+a[n-2]
        else if (first + first_next < last + last_previous){
            cout << "\n-------Debug 2.2----";
            if ((first + first_next)*2 <= last + last_previous){
                cout << "\n-------Debug 2.2.1--";
                if (last > last_previous){
                    cout << "\n-------Debug 2.2.1.1-valueToReturn="<<valueToReturn;
                    valueToReturn = last;
                    nums.erase(nums.begin()+nums.size()-1);
                    cout << "\n-------Debug 2.2.1.2-valueToReturn="<<valueToReturn;
                }
                else {
                    valueToReturn = first;
                    nums.erase(nums.begin());
                }
            }
            else {
                cout << "\n-------Debug 2.2.2--";
                valueToReturn = first;
                // nums.erase(nums.end());
                nums.erase(nums.begin());
            }
        }
        else {
            cout << "\n-------Debug 2.3----";
            if (first < last) {
                cout << "\n-------Debug 2.2.1----";
                valueToReturn = last;
                // nums.erase(nums.end());
                nums.erase(nums.begin()+nums.size()-1);
            }
            else {
                cout << "\n-------Debug 2.2.2----";
                valueToReturn = first;
                nums.erase(nums.begin());
            }
        }
    }

    cout << "\n-------Debug 3, valueToreturn="<<valueToReturn<<"------";
    return valueToReturn;
}

bool PredictTheWinner(vector<int>& nums) {
    
    bool player1Won = false;
    int arraySize = nums.size();
    // iterating the array and getting the score for each player
    for (int i=0; i<arraySize; i++){
        // Debugging
        cout << "\n----Debugging to print the array----";
        for (int i=0; i<nums.size(); i++){
            cout << nums[i] << " ";
        }
        // even iterations are for player 1 --- 0, 2, 4, 6, ...
        if (i%2==0){
            score1 += WhatToSelect(nums);
            printf("\n--For i = %d, score1 = %d, score2 = %d --", i, score1, score2);
        }

        // odd iterations are for player 2 --- 1, 3, 5, 7, ...
        else if (i%2==1){
            score2 += WhatToSelect(nums);
            printf("\n--For i = %d, score1 = %d, score2 = %d --", i, score1, score2);
        }
    }

    if (score1 > score2) player1Won = true;

    return player1Won;
}

int main(){
    // vector<int> nums = {2,4,55,1}; // correct
    // vector<int> nums = {5,232,231,7}; // correct
    // vector<int> nums = {10, 50, 5, 30}; // correct
    // vector<int> nums = {5, 10, 500, 200}; // correct
    vector<int> nums = {10,17,11,16,17,9,14,17,18,13,11,4,17,18,15,3,13,10};
    // 10,10 - 10r
    // 10,13 - 13
    // 10, 3 -  3
    // 10,15 - 10
    // 17
    // 11
    // 15
    // 16
    // 17
    // 9
    // 14
    // 18
    // 17r
    // 4
    // 11
    // 13
    // 17
    // 18
    // p1 = 121 should win

    cout << endl << PredictTheWinner(nums);
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