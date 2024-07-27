#include <iostream>
#include <vector>

using namespace std;

// Basic recursion -- O(2^(n/2))
int fib1(int n){
  if (n<=1){
    return 0;
  }
  if (n==2){
    return 1;
  }
  return fib1(n-1) + fib1(n-2);
}

// Using memorization - O(n)
long long fib2(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  
  vector<long long> arr(n + 1, -1);
  arr[0] = 0;
  arr[1] = 1;
  for (int i = 2; i <= n; i++) {
      arr[i] = arr[i - 1] + arr[i - 2];
  }

  return arr[n];
}

int main() {
  // cout << fib1(50); // 0 1 1 2 3 5 8 13 21 34
  cout << fib2(50) <<endl;
}