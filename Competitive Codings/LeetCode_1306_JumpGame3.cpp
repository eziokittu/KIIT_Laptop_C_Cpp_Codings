// LeetCode Problem - 1306 Jump Game 3
// https://leetcode.com/problems/jump-game-iii/

#include <iostream>
#include <vector>

using namespace std;

bool markArr(vector<int> &arr, vector<int> &mark, int index)
{
    // checking out of bounds
    if (index < 0 || index >= arr.size())
    {
        return false;
    }

    // marking the index
    if (mark[index] == 1)
    { // if already marked
        return false;
    }
    else if (mark[index] == 0)
    { // marking if not
        mark[index] = 1;
    }

    // if 0 is found
    if (arr[index] == 0)
    {
        return true;
    }
    else
    {
        return (
            markArr(arr, mark, index - arr[index]) || 
            markArr(arr, mark, index + arr[index])
        );
    }
}

bool canReach(vector<int> &arr, int start)
{
    vector<int> mark;
    for (int i=0; i<arr.size(); i++){
        mark.push_back(0);
    }

    return markArr(arr, mark, start);
}

int main()
{
    // vector<int> nums = {1,2,2,1,0,5};
    vector<int> nums = {7,2,1,0,3,2,1,7}; // 6
    // vector<int> nums = {4,2,3,0,8,1,8}; // 5
    cout << canReach(nums, 6);

    return 0;
}
