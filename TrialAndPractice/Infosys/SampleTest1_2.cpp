#include <iostream>
#include <vector>
using namespace std;

#define MOD 10000

int main()
{
  int n, k;
  cin >> n >> k;

  // DP table, dp[i][j] means number of arrays of length i ending with j
  vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

  // Initial state: length 1 arrays
  for (int i = 1; i <= n; ++i)
  {
    dp[1][i] = 1;
  }

  // Fill the DP table
  for (int length = 1; length < k; ++length)
  {
    for (int last = 1; last <= n; ++last)
    {
      if (dp[length][last] > 0)
      {
        for (int next = last; next <= n; next += last)
        {
          dp[length + 1][next] = (dp[length + 1][next] + dp[length][last]) % MOD;
        }
      }
    }
  }

  // Sum all the arrays of length k
  int result = 0;
  for (int i = 1; i <= n; ++i)
  {
    result = (result + dp[k][i]) % MOD;
  }

  cout << result << endl;

  return 0;
}
