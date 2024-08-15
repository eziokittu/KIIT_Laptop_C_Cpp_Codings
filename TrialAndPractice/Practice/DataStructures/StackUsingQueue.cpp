#include <iostream>
#include <queue>

using namespace std;

// METHOD 1
// Making push method costly
class Stack_Method1 {
  queue<int> q1;
  queue<int> q2;
  int n;

  public:
    Stack_Method1 () {
      n = 0;
    }

    void Push(int x){
      q2.push(x);
      n++;
      while (!q1.empty()){
        q2.push(q1.front());
        q1.pop();
      }

      queue<int> temp = q1;
      q1 = q2;
      q2 = temp;

      while (!q2.empty()){
        q2.pop();
      }
    }

    int Top(){
      if (q1.empty()){
        cout << "Stack is empty!\n";
        return -1;
      }
      int x = q1.front();
      return x;
    }

    bool Empty() {
      return n==0;
    }

    int Size() {
      return n;
    }

    void Pop() {
      q1.pop();
      n--;
    }
};

// METHOD 2
// Making pop method costly
class Stack_Method2 {
  queue<int> q1;
  queue<int> q2;
  int n;

  public:
    Stack_Method2 () {
      n = 0;
    }

    void Push(int x){
      q1.push(x);
      n++;
    }

    void Pop(){
      if (q1.empty()){
        cout << "Stack is empty!\n";
        return;
      }
      while (q1.size() > 1){
        q2.push(q1.front());
        q1.pop();
      }

      q1.pop();
      n--;

      queue<int> temp = q1;
      q1 = q2; 
      q2 = temp;
    }

    int Top() {
      if (q1.empty()){
        cout << "Stack is empty!\n";
        return -1;
      }
      while (q1.size() > 1){
        q2.push(q1.front());
        q1.pop();
      }
      int ans = q1.front();
      q2.push(ans);

      queue<int> temp = q1;
      q1 = q2;
      q2 = temp;

      return ans;
    }

    int Size () {
      return n;
    }

    bool Empty() {
      return n==0;
    }
};

void Stack_Method1_test() {
  Stack_Method1 st = Stack_Method1();
  cout << "Size of stack is "<< st.Size() << endl;
  cout << "Top of Stack is "<< st.Top() << endl;
  st.Push(2);
  st.Push(3);
  st.Push(4);
  st.Push(5);
  cout << "Size of stack is "<< st.Size() << endl;
  cout << "Top of Stack is "<< st.Top() << endl;
  st.Pop();
  cout << "Size of stack is "<< st.Size() << endl;
  cout << "Top of Stack is "<< st.Top() << endl;
}

void Stack_Method2_test() {
  Stack_Method2 st = Stack_Method2();
  cout << "Size of stack is "<< st.Size() << endl;
  cout << "Top of Stack is "<< st.Top() << endl;
  st.Push(2);
  st.Push(3);
  st.Push(4);
  st.Push(5);
  cout << "Size of stack is "<< st.Size() << endl;
  cout << "Top of Stack is "<< st.Top() << endl;
  st.Pop();
  cout << "Size of stack is "<< st.Size() << endl;
  cout << "Top of Stack is "<< st.Top() << endl;
}

int main() {
  // Stack_Method1_test();
  Stack_Method2_test();
}