#include <iostream>
#include <stack>

using namespace std;

int CountRedundantParenthesis(string exp){
  stack<char> st;
  int ans = 0;
  for (char c : exp) {
    if (c=='(' || c=='+' || c=='-' || c=='/' || c=='*') {
      st.push(c);
    }
    else if (c==')') {
      if (st.top()=='('){
        ans++;
      }
      while (st.top()!='('){
        st.pop();
      }
      st.pop();
    }
  }
  return ans;
}

int main() {
  string s = "((4 + 4))";
  cout << CountRedundantParenthesis(s) << endl;
}