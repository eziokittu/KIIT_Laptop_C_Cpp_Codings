#include <iostream>
#include <stack>

using namespace std;

string ReverseStringUsingStack(string s){
  stack<string> st;
  string buffer = "";
  for (char c : s){
    if (c != ' '){
      buffer += c;
    }
    else {
      st.push(buffer);
      buffer = "";
    }
  }
  st.push(buffer);
  string ans = "";
  while (!st.empty()){
    ans += st.top();
    ans += " ";
    st.pop();
  }
  return ans;
}

void DisplayStack(stack<int> st){
  cout << "Displaying the Stack: ";
  while (!st.empty()){
    cout << st.top() << " ";
    st.pop();
  }
  cout<<endl;
}

stack<int> ReverseAStack_UsingAnotherStack(stack<int> st){
  stack<int> ans;
  while (!st.empty()){
    ans.push(st.top());
    st.pop();
  }
  return ans;
}

// Utility function
void InsertAtBottom(stack<int> &st, int element) {
  if (st.empty()){
    st.push(element);
    return;
  }

  int topElement = st.top();
  st.pop();
  InsertAtBottom(st, element);
}

void ReverseAStack_Recursive(stack<int> &st){
  if (st.empty()) {
    return;
  }
  int element = st.top();
  st.pop();
  ReverseAStack_Recursive(st);
  InsertAtBottom(st, element);
}

void test1() {
  string s = "Hey, you are looking cute today Anshika!";
  cout << "Original:\n"<<s;
  cout << "\nReverse:\n"<<ReverseStringUsingStack(s);
}

void test2() {
  stack<int> st;
  st.push(23);
  st.push(34);
  st.push(45);
  st.push(56);
  DisplayStack(st);
  stack<int> ans = ReverseAStack_UsingAnotherStack(st);
  DisplayStack(ans);
}

void test3() {
  stack<int> st;
  st.push(23);
  st.push(34);
  st.push(45);
  st.push(56);
  DisplayStack(st);
  ReverseAStack_Recursive(st);
  DisplayStack(st);
}

int main () {
  // test1();
  // test2();
  test3();
}