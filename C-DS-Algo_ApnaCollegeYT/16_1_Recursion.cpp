#include <iostream>

using namespace std;

int SumofN(int n){
  if (n<=1){
    return n;
  }
  return n + SumofN(n-1);
}

int factorial(int n){
  if (n<=1){
    return 1;
  }
  return n * factorial(n-1);
}

int main() {
  cout << SumofN(10) << endl;
  cout << factorial(5);
}