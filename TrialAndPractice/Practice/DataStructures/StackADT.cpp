#include <iostream>
#include <vector>

using namespace std;

#define n 100

class Stack {
  int *arr;
  int top;
  int size;

  public:
    Stack () {
      size = n;
      top = -1;
      arr = new int[n];
    }

    void Push (int x){
      if (top == n-1){
        cout << "Trying to push() stack, but stack is overflow!\n";
        return;
      }
      cout << "The Stack is pushed with value '"<<x<<"'\n";
      arr[++top] = x;
    }

    void Pop () {
      if (top == -1){
        cout << "Trying to pop() stack, but stack is underflow!\n";
        return;
      }
      cout << "The Stack is popped!\n";
      top--;
    }

    int Top() {
      if (top == -1){
        cout << "Trying to pop() stack, but stack is underflow!\n";
        return -1;
      }
      return arr[top];
    }

    bool IsEmpty() {
      return (top==-1);
    }
};

int main() {
  Stack st1;
  st1.Push(19);
  cout << "Top of the Stack is: " << st1.Top() << endl;
  st1.Push(34);
  cout << "Top of the Stack is: " << st1.Top() << endl;
  st1.Pop();
  cout << "Top of the Stack is: " << st1.Top() << endl;
  cout << "Stack is empty? "<<(st1.IsEmpty()==false ? "FALSE" : "TRUE") <<endl;
  st1.Pop();
  cout << "Stack is empty? "<<(st1.IsEmpty()==false ? "FALSE" : "TRUE") <<endl;
  st1.Pop();
}