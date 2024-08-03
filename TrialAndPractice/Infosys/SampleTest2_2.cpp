#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(2));

  for (int i = 0; i < n; ++i)
  {
    cin >> a[i][0] >> a[i][1];
  }

  // DP table to store the maximum sum for each cell
  vector<vector<int>> dp(n, vector<int>(2, 0));

  // Initialize the DP table with the values of the last row
  dp[n - 1][0] = a[n - 1][0];
  dp[n - 1][1] = a[n - 1][1];

  // Fill the DP table from bottom to top
  for (int i = n - 2; i >= 0; --i)
  {
    for (int j = 0; j < 2; ++j)
    {
      if (a[i + 1][0] > a[i][j])
      {
        dp[i][j] = max(dp[i][j], a[i][j] + dp[i + 1][0]);
      }
      if (a[i + 1][1] > a[i][j])
      {
        dp[i][j] = max(dp[i][j], a[i][j] + dp[i + 1][1]);
      }
    }
  }

  // The answer is the maximum value starting from the first row
  int result = max(dp[0][0], dp[0][1]);
  cout << result % MOD << endl;

  return 0;
}
