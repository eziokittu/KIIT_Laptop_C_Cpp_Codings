#include <iostream>

using namespace std;

// Sieve of Eratosthenes - optimized way of getting all the prime numbers in a range
// - say we take a range of 50. so we start from 2 and keep marking all the elements
// - all elements divisible by 2 are marked (other than 2 itself)
// - next we mark all divisible by 3 (other than 3 itself) ... we keep doing this
// if an element is already marked we dont search that element
// for optimizing the loop further, we start searching the elements from square of that 
// - that is- for 7 we start searching from 7^2

void PrimeNumbers_SieveOfEratosthenes(int n){

  // initialize the array to mark elements
  int prime[n+1] = {0};

  // we loop the entire array and search only if the element is not marked
  for (int i=2; i<=n; i++){
    if (prime[i]==0){
      for (int j=i*i; j<=n; j+=i){
        prime[j] = 1;
      }
    }
  }

  // After all the elements are marked, we print those which are not
  cout <<"\nAll the prime numbers till "<<n<<" are:";
  for (int i=2; i<=n; i++){
    if (prime[i]==0){
      cout << " "<<i;
    }
  }
}

void PrimeFactors_SieveOfEratosthenes(int n){
  // smallest prime factors array
  int spf[n] = {0};
  for (int i=2; i<=n; i++){
    spf[i] = i;
  }

  for (int i=2; i<=n; i++) {
    if (spf[i] == i){
      for (int j=i*i; j<=n; j+=i){
        if (spf[j] == j){
          spf[j] = i;
        }
      }
    }
  }

  while (n!=1){
    cout << spf[n] << " ";
    n /= spf[n];
  }
}

int main() {
  // PrimeNumbers_SieveOfEratosthenes(100);
  PrimeFactors_SieveOfEratosthenes( 1124);
}