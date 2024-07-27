#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Problem statement - 
// We have a set of coins of values say - 5,4,1
// Now we have to find the minimum no. of coins to achieve a target value, say 13
// The greedy approach will have the solution as --> 5+5+1+1+1 --> 5 coins
// But the optimal solution is --> 5+4+4 --> 3 coins

// Bottom up approach
int minCoins(int target, vector<int> coins){
  int memo[target] = {1000000000};
  memo[0] = 0;

  for (int i=1; i<=target; i++){
    for (int coin : coins){
      int subproblem = i - coin;
      if (subproblem < 0){
        continue;
      } 
      memo[i] = min(memo[i], memo[subproblem] + 1);
    }
  }

  return memo[target];
}

int main() {
  vector<int> coins = {5, 4, 1};
  int target = 13;
  cout << minCoins(target, coins);
}

// incomplete