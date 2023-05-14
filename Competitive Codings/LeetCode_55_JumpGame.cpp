// Leetcode Problem 55 - Jump Game
// https://leetcode.com/problems/jump-game/

#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums)
{
    // Special case --> length = 1
    if (nums.size() == 1)
    {
        return true;
    }

    int dist, index = 0;

    for (int i = 1; i < nums.size();)
    {
        dist = nums[index] + index;

        // exit condition
        if (dist >= nums.size() - 1)
        {
            return true;
        }

        int maxDist = dist, newIndex = 0;
        // loop
        for (int j = index + 1; j <= dist; j++)
        {
            if (maxDist < j + nums[j])
            {
                maxDist = j + nums[j];
                newIndex = j;
            }
        }

        // iterating
        i = newIndex;
        index = newIndex;

        // exit condition
        if (maxDist <= dist)
        {
            break;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {3, 3, 3, 2};
    cout << canJump(nums);

    return 0;
}