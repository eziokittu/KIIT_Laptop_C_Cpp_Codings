// Leetcode Problem 592 - Fraction Addition and Subtraction

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Utility function to find GCD of 'a' and 'b'
int gcd(int a, int b){
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// Returns LCM of array elements
int findLCM(vector<int> arr, int n){
  // Initialize result
  int ans = arr[0];

  // ans contains LCM of arr[0], ..arr[i] after i'th iteration,
  for (int i = 1; i < n; i++) {
    ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));
  }
  return ans;
}

pair<int, int> getNumDeno(int n, int d){
  if (n<0){
    n = -n;
  }
  int b = (n > d ? d : n);
  int a = sqrt(abs(b));
  for (int i=2; i<=a; i++){
    while (n%i==0 && d%i==0){
      n = n/i;
      d = d/i;
    }
  }
  return {n, d};
}

    // utility function to get all the fractions
vector<pair<pair<int, int>, char>> getNums(string e){
  vector<pair<pair<int, int>, char>> v;
  int a=0, b=0;
  char op = '+';
  bool nextNum = false;

  for (char c : e) {

  // resetting getting the next set of fraction
  if (c == '+' || c == '-'){
    if (a==0 && b==0){
      op = c;
      continue;
    }
    pair<int, int> nums = {a,b};
    pair<pair<int, int>, char> p = {nums, op};
    v.push_back(p);
    a=0;
    b=0;
    op = c;
    nextNum = false;
  }

  // getting the numbers
  if (c == '/'){
    nextNum = true;
  }
  if (c>='0' && c<='9'){
    if (nextNum){
      b = (b*10) + (c-'0');
    }
    else {
      a = (a*10) + (c-'0');
    }
  }
}

  // for the last number
  pair<int, int> nums = {a,b};
  pair<pair<int, int>, char> p = {nums, op};
  v.push_back(p);

  return v;
}

vector<int> getDenos(vector<pair<pair<int, int>, char>> v){
  vector<int> d;
  for (auto i : v){
    d.push_back(i.first.second);
  }
  return d;
}

string fractionAddition(string e) {
  vector<pair<pair<int, int>, char>> v = getNums(e);
  vector<int> denos = getDenos(v);
  int denominator = findLCM(denos, denos.size());
  int numerator = 0;
  for (auto i : v){
    if (i.second == '+'){
      numerator = numerator + (denominator / i.first.first);
    }
    else {
      numerator = numerator - (denominator / i.first.first);
    }
  }
  if (numerator % denominator == 0){
    numerator = numerator/denominator;
    denominator = 1;
  }

  pair<int, int> nd = getNumDeno(numerator, denominator);

  string ans = "";
  if (numerator < 0){
    ans += '-';
  }
  ans += to_string(nd.first);
  ans += '/';
  ans += to_string(nd.second);

  return ans;
}

int main() {
  cout << fractionAddition("-1/2+1/2")<<endl;
  cout << fractionAddition("-1/2-1/2")<<endl;
  cout << fractionAddition("1/2-1/3")<<endl; // should be 1/6
}