#include <iostream>
#include <queue>
#include <stack>

using namespace std;

static int functionCallCount = -1;

struct Node {
  public:
    int val;
    Node* prev;
    Node* next;

    Node () {
      val = 0;
      prev = nullptr;
      next = nullptr;
    }
    Node (int _val) {
      val = _val;
      prev = nullptr;
      next = nullptr;
    }
    Node (Node* _prev, int _val, Node* _next) {
      val = _val;
      prev = _prev;
      next = _next;
    }
};

struct DoublyCircularLinkList {
  public:
    Node* root;

    // Constructor to create an empty Linked list
    DoublyCircularLinkList () {
      functionCallCount++;
      root = nullptr;
      cout<<"\n ["<<functionCallCount<<"] Instantiated a new Doubly Circular linked list";
    }

    // Constructor to create a Linked list with single node
    DoublyCircularLinkList (int _val) {
      functionCallCount++;
      Node* temp = new Node(_val);
      root = temp;
      SetLinks(root, root);
      cout<<"\n ["<<functionCallCount<<"] Instantiated a new Doubly Circular linked list";
    }

    void AddNodeAtEnd (int _val=0){
      functionCallCount++;
      if (root==nullptr){
        Node* temp = new Node(_val);
        root = temp;
        SetLinks(root,root);
      }
      else {
        Node* p = root->prev;
        Node* temp = new Node(p, _val, root);
        root->prev = temp;
        p->next = temp;
      }
      cout<<"\n ["<<functionCallCount<<"] Added a node at the end!";
    }

    void AddNodeAtStart (int _val=0){
      functionCallCount++;
      if (root==nullptr){
        Node* temp = new Node(_val);
        root = temp;
        SetLinks(root,root);
      }
      else {
        Node* p = root->prev;
        Node* temp = new Node(p, _val, root);
        root->prev = temp;
        p->next = temp;

        // one line difference from AddNodeAtEnd()
        root = temp;
      }
      cout<<"\n ["<<functionCallCount<<"] Added a node at the start!";
    }

    void DeleteNodeAtEnd (){
      functionCallCount++;
      if (root->next == root){
        delete(root);
        root = nullptr;
      }
      else if (root->next == root->prev) {
        delete(root->prev);
        SetLinks(root, root);
      }
      else {
        Node* p = root->prev->prev;
        delete(root->prev);
        p->next = root;
        root->prev = p;
      }
      cout <<"\n ["<<functionCallCount<<"] Deleted node at end!";
    }

    void DeleteNodeAtStart (){
      functionCallCount++;
      if (root->next == root){
        delete(root);
        root = nullptr;
      }
      else if (root->next == root->prev){
        root = root->next;
        delete(root->prev);
        SetLinks(root, root);
      }
      else {
        Node* p = root->next;
        Node* q = root->prev;
        delete(root);
        q->next = p;
        p->prev = q;
        root = p;
      }
      cout <<"\n ["<<functionCallCount<<"] Deleted node at start!";
    }

    void SetLinks(Node* _prev, Node* _next){
      functionCallCount++;
      root->prev = _prev;
      root->next = _next;
    }

    void PrintAllNodes (){
      functionCallCount++;
      if (root == nullptr){
        cout << "\n ["<<functionCallCount<<"] No nodes exist in this Linked list";
        return;
      }
      int count = 1;
      Node *p = root;
      cout << "\n ["<<functionCallCount<<"] Printing the Doubly circular Linked List: | ";
      while (p->next != root){
        count++;
        cout << p->val << " --> ";
        p = p->next;
      }
      cout << p->val << " | --- There are '"<<count<<"' nodes in total.";
    }
};

void testing1 () {
  stack<int> s;
  queue<int> q;
  cout << "Enqueuing data into queue\n";
  for (int i=0; i<10; i++){
    q.push(i+1);
  }
  cout << "Pusing data into stack\n";
  for (int i=0; i<10; i++){
    s.push(i+1);
  }

  cout << "\nPrinting the queue: ";
  while (!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
  cout << "\nPrinting the stack: ";
  while (!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
}

void testing2 () {
  DoublyCircularLinkList dcll = DoublyCircularLinkList(11);
  dcll.PrintAllNodes();
  dcll.DeleteNodeAtStart();
  dcll.PrintAllNodes();
  dcll.AddNodeAtStart(34);
  dcll.PrintAllNodes();
  dcll.AddNodeAtStart(45);
  dcll.AddNodeAtStart(56);
  dcll.PrintAllNodes();
  dcll.AddNodeAtEnd(67);
  dcll.AddNodeAtEnd(78);
  dcll.AddNodeAtEnd(89);
  dcll.AddNodeAtEnd();
  dcll.AddNodeAtEnd(91);
  dcll.PrintAllNodes();
  dcll.DeleteNodeAtEnd();
  dcll.PrintAllNodes();
  dcll.DeleteNodeAtStart();
  dcll.PrintAllNodes();
  dcll.DeleteNodeAtEnd();
  dcll.DeleteNodeAtStart();
  dcll.PrintAllNodes();
  dcll.DeleteNodeAtEnd();
  dcll.DeleteNodeAtStart();
  dcll.PrintAllNodes();
  dcll.DeleteNodeAtStart();
  dcll.PrintAllNodes();
}

int main() {
  // function for testing the stack and quesues in c++ STL
  // testing1();

  // function to test a doubly circular linked list
  testing2();
}