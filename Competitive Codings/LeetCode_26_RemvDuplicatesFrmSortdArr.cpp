// Leetcode problem - EASY - 26 - Remove duplicates from sorted array (sorted in non-decreasing order)
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    for (int i=1; i<nums.size(); i++){
        int forward = 0;
        int backward = 0;

        // get start and end position of all same elements
        int start=i, end=i+1;
        for (int j=i+1; j<nums.size(); j++){
            if (nums[i] == nums[j]) end++;
            else break;
        }

        // forward
        for (int j=i+1; j<nums.size(); j++){
            if (nums[i] == nums[j]) forward++;
        }

        // backward
        for (int j=0; j<i; j++){
            if (nums[i] == nums[j]) backward++;
        }

        //erase the element in that FORWARD index range
        if (forward>0){

            // cout << "\nPrinting---Before Erase\n";
            // // printing after remove of duplicates
            // for(int i=0;i<nums.size();i++){
            //     cout << nums[i] << " ";
            // }
            // cout <<", Start="<<start<<", End="<<end;

            nums.erase(nums.begin()+start+1, nums.begin()+end);
            i=start;

            // cout << "\nPrinting---After Erase Forward\n";
            // // printing after remove of duplicates
            // for(int i=0;i<nums.size();i++){
            //     cout << nums[i] << " ";
            // }
        }
        //erase the element in that FORWARD index range
        if (backward>0){
            nums.erase(nums.begin()+start);

            // cout << "\nPrinting---After Erase Backward\n";
            // // printing after remove of duplicates
            // for(int i=0;i<nums.size();i++){
            //     cout << nums[i] << " ";
            // }
        }
    }
    return nums.size();
}

int main(){

    // vector<int> nums = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6};
    // vector<int> nums = {5,5,5,5,5,6,6,7,7,7,8,8,8,8,9};
    // vector<int> nums = {1,8,33,55,286,500,500,767};
    // vector<int> nums = {};
    // vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    // vector<int> nums = {1,1,2};
    vector<int> nums = {1,1,1,2,2,2};
    // vector<int> nums = {1,2,2};

    // printing before remove of duplicates
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }

    // printing the no. of unique elements
    cout << endl << removeDuplicates(nums) << endl;

    // printing after remove of duplicates
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
}