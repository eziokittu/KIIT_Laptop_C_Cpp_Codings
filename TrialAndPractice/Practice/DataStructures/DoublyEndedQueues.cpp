#include <iostream>
#include <deque>
#include <vector>
#include <set>

using namespace std;

// Sliding window maximum problem, with window size given for an array
vector<int> GetSlidingWindowMax(vector<int> arr, int k){
  deque<int> dq;
  for (int i=0; i<k; i++){
    dq.push_front(arr[i]);
  }

  for (int i=k-1; i<arr.size(); i++){
    
  }
}

// Problem - Sliding Window Max
void test2() {
  vector<int> nums = {1,-4,-2,-1,0,32,1,-8,-19,-11,5};
}

// PUSH and POP can take place from both front and back of the queue
void test1 () {
  deque<int> dq;
  dq.push_front(1);
  dq.push_back(2);
  dq.push_front(3);
  dq.push_back(4);

  // iterated from FRONT to BACK of the deque
  for (auto i : dq){
    cout << i << " ";
  }
}

void test2 () {

}

int main() {
  test1();
}