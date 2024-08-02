#include <iostream>
#include <vector>

using namespace std;

// Problem Statement - Sample 1 - EASY
// You are given a binary string S. 
// You can perform the following operations 
// on S any number of times (possibly zero): 

// i)  Select an index i such that S[i] is equal to 1 and 
// S[i+1] is equal to 0 for 0 ≤ i < len(S) -1. 

// ii) Remove exactly one of the character from S.  
// Find the smallest string S that you can get after 
// performing operations on S.

// Note: If there are multiple smallest strings possible then 
// return the string which is lexicographically smallest. 

// Constraints 
// 1  <=  len(s)   <=  10^5 
// 1  <=  𝐴[i]   <=  10^5

// Sample Input 1 
// 0000111111 
// Sample output 1 
// 0000111111
// Explanation-1 
// Here, S = "0000111111" We cannot perform any operation on 
// S so it remains unchanged 
 
// Sample Input 2 
// 1111111 
// Sample output 2 
// 1111111 
// Explanation 2 
// Here, S = "1111111" There exists no 0 in S so we 
// can not perform any operation on S. Hence, S is 
// equal to "1111111". 
// 37 
 
// Sample Input 3 
// 110 
// Sample output 3 
// 0 
// Explanation 3 
// Here, S = "110" We can perform two operations on S as :- 1. Select the 
// index 1 and 2 and remove the character at index 1. Then S becomes 
// "10". 2. Select the index 0 and 1 and remove the character at index 0. 
// Then S becomes "0". Hence, S after performing operations is equal to 
// "0"

string GetSmallestString(string s){
  string ans = "";
  string buffer = "";
  bool onePresent = false;

  // Iterating the string
  for (int i=0; i<s.size(); i++) {

    // When '1' does not exist previously but has a '0'
    if (onePresent==false && s[i]=='0'){
      ans += s[i];
    }

    // when there is a '1' and buffer != "0"
    else if (s[i]=='1' && buffer!="0"){
      onePresent = true;
      buffer += s[i];
    }

    // when there is a '1' and buffer == "0"
    else if (s[i]=='1' && buffer=="0"){
      onePresent = true;
      ans += '0';
      buffer = "1";
    }

    // When '1' exists previously and now has a '0' and buffer is not "0"
    else if (onePresent==true && s[i]=='0' && buffer!="0"){
      buffer = "0";
    }

    // When '1' exists previously and now has a '0' and buffer is == "0"
    else if (onePresent==true && s[i]=='0' && buffer=="0"){
      continue;
    }
  }

  // when string iteration exits but buffer is not empty
  if (buffer != ""){
    ans += buffer;
  }
  return ans;
}

// Main Function
int main() {
  vector<string> str = {
    "111000", "111001", "00100", "00000", "11111", "11110", "000111", "111000"
  };
  for (string s : str){
    cout << "Smallest string for '"<< s <<"' is "<< GetSmallestString(s) << endl;
  }
}

// OUTPUT
// Smallest string for '111000' is 0
// Smallest string for '111001' is 01
// Smallest string for '00100' is 000
// Smallest string for '00000' is 00000
// Smallest string for '11111' is 11111
// Smallest string for '11110' is 0
// Smallest string for '000111' is 000111
// Smallest string for '111000' is 0