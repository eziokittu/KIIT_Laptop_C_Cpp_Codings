#include <iostream>
#include <vector>

using namespace std;

int optimalSelection(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    // Fill the diagonal elements of dp[][]
    for (int i = 0; i < n; i++) {
        dp[i][i] = nums[i];
    }

    // Build dp[][] in bottom-up manner
    for (int gap = 1; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            int x = i + 2 <= j ? dp[i + 2][j] : 0;
            int y = i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0;
            int z = i <= j - 2 ? dp[i][j - 2] : 0;

            dp[i][j] = std::max(nums[i] + std::min(x, y), nums[j] + std::min(y, z));
        }
    }

    return dp[0][n - 1];
}

int GetMaxPoints(vector<int> markers) {
    return optimalSelection(markers);
}

int main() {
    vector<int> m = {1,2,3,4,5,6};
    int result = GetMaxPoints(m);
    std::cout << "Maximum score: " << result << std::endl;

    return 0;
}

