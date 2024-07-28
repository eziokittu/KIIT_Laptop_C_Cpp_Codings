#include <iostream>
#include <stack>

using namespace std;

// Queue using 2 stacks - Making dequeue costly
class Queue {
  stack<int> st1;
  stack<int> st2;

  public:
    // O(1)
    void Enqueue(int x){
      cout<<"Element "<< x <<" has been enqueued\n";
      st1.push(x);
    }

    // O(n)
    int Dequeue(){
      if (!st2.empty()){
        int x = st2.top();
        st2.pop();
        cout<<"Element has been dequeued\n";
        return x;
      }
      else {
        if (st1.empty()){
          cout<<"Cannot dequeue since the queue is empty!\n";
          return -1;
        }
        else {
          while (!st1.empty()){
            st2.push(st1.top());
            st1.pop();
          }
          int x = st2.top();
          st2.pop();
          cout<<"Element has been dequeued\n";
          return x;
        }
      }
    }

    // only stack 1 is used 
    int Dequeue_Recursive() {

      // if no elements
      if (st1.empty()){
        cout << "Queue is Empty!\n";
        return -1;
      }

      int x = st1.top();
      // If only 1 element in queue
      st1.pop();
      if (st1.empty()){
        return x;
      }

      // More than 1 element were present
      int item = Dequeue_Recursive();
      st1.push(x);
      return item;
    }
};

int main() {
  Queue q;
  q.Dequeue();
  q.Enqueue(4);
  cout << "After Dequeue: " << q.Dequeue() << endl;
  q.Enqueue(5);
  q.Enqueue(6);
  q.Enqueue(7);
  q.Enqueue(8);
  cout << "After Dequeue: " << q.Dequeue() << endl;
  cout << "After Dequeue: " << q.Dequeue() << endl;
  cout << "After Dequeue: " << q.Dequeue_Recursive() << endl;
}