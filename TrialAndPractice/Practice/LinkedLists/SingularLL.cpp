#include <iostream>
#include <vector>

using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node (){
      data = 0;
      next = nullptr;
    }

    Node (int _data){
      data = _data;
      next = nullptr;
    }

    Node (int _data, Node* _next){
      data = _data;
      next = _next;
    }
};

class LinkedList {
  public:
    Node* root;
    int n;

    LinkedList() {
      if (root == nullptr){
        Node *temp = new Node();
        root = temp;
        cout << "New Linked List created.\n";
      }
    }

    LinkedList (vector<int> arr) {
      Node *p = root;
      for (int i=0; i<arr.size(); i++){
        Node *temp = new Node(arr[i]);
        if (p==nullptr){
          root = temp;
          p = temp;
        }
        else{
          p->next = temp;
          p = p->next;
        }
      }
      cout << "New Linked List Created with array data (or added to existing Linked List).\n";
    }

    int GetLinkedListSize() {
      Node *p = root;
      int size = 0;
      while (p != nullptr){
        size++;
        p = p->next;
      }
      return size;
    }

    void AddNode_End(int _data){
      Node *temp = new Node(_data);
      if (root == nullptr){
        root = temp;
        return;
      }

      Node *p = root;
      while (p->next != nullptr){
        p = p->next;
      }
      p->next = temp;

      cout <<"New node '"<< _data<<"' added to the END of the Linked List.\n";
    }

    void AddNode_Start(int _data){
      Node *temp = new Node(_data);
      if (root == nullptr){
        root = temp;
        return;
      }

      temp ->next = root;
      root = temp;

      cout <<"New node '"<< _data<<"' added to the START of the Linked List.\n";
    }

    void AddNode_Pos(int _data, int pos){
      if (pos<=1) {
        AddNode_Start(_data);
        return;
      }
      int s = GetLinkedListSize();
      if (pos>s) {
        AddNode_End(_data);
        return;
      }
      
      s = 1;
      Node *p = root;
      while(s!=pos-1) {
        p = p->next;
        s++;
      }
      
      Node *temp = new Node(_data, p->next);
      p->next = temp;

      cout <<"New node '"<< _data<<"' added to POsition '"<<pos<<"' of the Linked List.\n";
    }

    void DeleteNode_Start(){
      Node *p = root;
      if (p==nullptr) {
        return;
      } 
      else if (p->next==nullptr){
        delete(p);
        root = nullptr;
        return;
      }

      root = p->next;
      delete(p);

      cout <<"Node deleted at the START of the Linked List.\n";
    }

    void DeleteNode_End(){
      Node *p = root;
      if (p==nullptr) {
        return;
      } 
      else if (p->next==nullptr){
        delete(p);
        root = nullptr;
        return;
      }

      while (p->next->next != nullptr){
        p = p->next;
      }
      Node *temp = p->next;
      delete(temp);
      p->next = nullptr;

      cout <<"Node deleted at the END of the Linked List.\n";
    }

    void DeleteNode_Pos(int pos){
      if (pos<=1) {
        DeleteNode_Start();
        return;
      }
      int s = GetLinkedListSize();
      if (pos>=s) {
        DeleteNode_End();
        return;
      }

      s = 2;
      Node *p = root;
      while (s != pos) {
        s++;
        p = p->next;
      }

      Node *temp = p->next->next;
      delete(p->next);
      p->next = temp;

      cout <<"Node deleted at the position '"<<pos<<"' of the Linked List.\n";
    }

    void PrintLinkedList() {
      if (root == nullptr){
        cout << "Singular Linked List is EMPTY.\n";
        return;
      }
      Node *p = root;
      cout << "Printing the Singular Linked List: ";
      while (p!=nullptr){
        cout << p->data;
        p = p->next;
        if (p!=nullptr){
          cout << " --> ";
        }
      }
      cout<<endl;
    }
};

Node* ReverseLinkedList(Node *root){
  Node *ans = root;
  if (root!=nullptr && root->next!=nullptr) {
    Node *p=nullptr, *q=root, *r=nullptr;
    while (q != nullptr){
      r = q->next;
      q->next = p;
      p = q;
      q = r;
    }
    ans = p;
  }
  cout << "Linked List has been reversed\n";
  return ans;
}

Node* ReverseLinkedList_recursive(Node *root){
  if (root==nullptr || root->next==nullptr){
    return root;
  }
  Node *newRoot = ReverseLinkedList_recursive(root->next);
  root->next->next = root;
  root->next = nullptr;
  return newRoot;
}

int main() {
  vector<int> arr = {-2,4,5,-3,9,34,1,0,45,32};
  LinkedList ll1 = LinkedList(arr);
  ll1.PrintLinkedList();
  ll1.AddNode_End(78);
  ll1.PrintLinkedList();
  ll1.AddNode_Start(-42);
  ll1.PrintLinkedList();
  ll1.AddNode_Pos(18, 5);
  ll1.PrintLinkedList();
  ll1.DeleteNode_Start();
  ll1.PrintLinkedList();
  ll1.DeleteNode_Pos(7);
  ll1.PrintLinkedList();
  ll1.root = ReverseLinkedList(ll1.root);
  ll1.PrintLinkedList();
  ll1.root = ReverseLinkedList_recursive(ll1.root);
  ll1.PrintLinkedList();
}