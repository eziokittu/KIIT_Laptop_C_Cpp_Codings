// LeetCode Problem 486 - Predict The winner
// https://leetcode.com/problems/predict-the-winner/

#include <iostream>
#include <vector>

using namespace std;

// bool Sum_AlwaysSelectFirst(vector<int> nums){
//     int sum_p1=0, sum_p2=0;
//     for (int i=0; i<nums.size(); i++){
//         if (i%2==0) sum_p1+=nums[i];
//         else sum_p2+=nums[i];
//     }
//     cout << "\nsum_p1="<<sum_p1<<", sum_p2="<<sum_p2;
//     if (sum_p1>=sum_p2) return true;
//     else return false;
// }

// bool Sum_AlwaysSelectLast(vector<int> nums){
//     int sum_p1=0, sum_p2=0;
//     for (int i=nums.size()-1; i>=0; i--){
//         if ((nums.size()-1-i)%2==0) sum_p1+=nums[i];
//         else sum_p2+=nums[i];
//     }
//     cout << "\nsum_p1="<<sum_p1<<", sum_p2="<<sum_p2;
//     if (sum_p1>=sum_p2) return true;
//     else return false;
// }

int WhoWillSelect(vector<int>& nums, bool turn, int s1, int s2){
    int sum_p1=0, sum_p2=0, t1=0, t2=0, max=nums.size()-1;
    bool optimalChoiceNotFound = true;

    if (nums[0] + nums[1] < nums[2]) t1 = nums[0];
    if (nums[max] + nums[max-1] < nums[max-2]) t2 = nums[max];
    if (t1>t2){
        if (turn==true) s2+=t1;
        else s2+=t1;
        nums.erase(nums.begin());
    } 
    else {
        if (turn==true) {
            s2+=t2;
            nums.pop_back();
            return s2;
        }
        else {
            s2+=t2;
            nums.pop_back();
        }
    }
    return s1;
}

bool PredictTheWinner(vector<int>& nums) {
    // if (Sum_AlwaysSelectFirst(nums)==true || Sum_AlwaysSelectLast(nums)==true) 
    //     return true;
    // else return false;

    if (nums.size()<=2) return true;
    else if (nums.size()==3){
        if (nums[1]<nums[0]+nums[2]) return true;
        else return false;
    }
    else{
        
    }
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