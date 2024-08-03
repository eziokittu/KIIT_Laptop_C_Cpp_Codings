#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10000;

// Function to count the number of valid arrays
int countArrays(int n, int k)
{
  vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

  // Initialize the dp array for length 1 arrays
  for (int i = 1; i <= n; ++i)
  {
    dp[1][i] = 1;
  }

  // Fill the dp array for arrays of length greater than 1
  for (int length = 2; length <= k; ++length)
  {
    for (int i = 1; i <= n; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        if (j % i == 0)
        {
          dp[length][j] = (dp[length][j] + dp[length - 1][i]) % MOD;
        }
      }
    }
  }

  // Sum up all the valid arrays of length k
  int result = 0;
  for (int i = 1; i <= n; ++i)
  {
    result = (result + dp[k][i]) % MOD;
  }

  return result;
}

int main()
{
  int n, k;
  cin >> n >> k;

  cout << countArrays(n, k) << endl;

  return 0;
}
