// Leetcode Problem 45 - Jump Game
// https://leetcode.com/problems/jump-game-ii/

#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int> &nums)
{
    // Special case --> length = 1
    if (nums.size() == 1)
    {
        return 0;
    }

    int dist, index = 0, count = 1;

    for (int i = 1; i < nums.size();)
    {
        dist = nums[index] + index;

        // main exit condition
        if (dist >= nums.size() - 1)
        {
            return count;
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
        count++;

        // exit condition
        if (maxDist <= dist) // not used since all are possible
        {
            break;
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {3, 3, 3, 2};
    cout << jump(nums);

    return 0;
}