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

void PrintLinkedList(Node *root) {

  if (root == nullptr){
    cout << "Singular Linked List is EMPTY.\n";
    return;
  }
  Node *p = root;
  cout << "Printing the Singular Linked List having nodes: ";
  while (p!=nullptr){
    cout << p->data << " ==> ";
    p = p->next;
    // if (p!=nullptr){
    //   cout << " --> ";
    // }
  }
  cout<< "NULL\n";
}

int GetLinkedListSize(Node *root) {
  Node *p = root;
  int size = 0;
  while (p != nullptr){
    size++;
    p = p->next;
  }
  return size;
}

class LinkedList {
  public:
    Node* root;
    int nodeCount = 0;
    bool hasCycle = false;

    LinkedList() : root(nullptr), nodeCount(0), hasCycle(false) {
      if (root == nullptr){
        Node *temp = new Node();
        root = temp;
        cout << "New Linked List created.\n";
      }
    }

    LinkedList (vector<int> arr) : root(nullptr), nodeCount(0), hasCycle(false) {
      Node* p = nullptr;
      for (int i = 0; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        if (root == nullptr) {
          root = temp;
          p = temp;
        } 
        else {
          p->next = temp;
          p = p->next;
        }
        nodeCount++;
      }
      cout << "New Linked List created with array data (or added to existing Linked List).\n";
    }

    // Function to connect a node at the end of the current Linked List
    void ConectNode(Node *node){
      if (root==nullptr){
        root = node;
        return;
      }
      Node *p = root;
      while (p->next != nullptr){
        p=p->next;
      }
      p->next = node;
    }

    void AddNode_End(int _data){
      nodeCount++;
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
      nodeCount++;
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
      nodeCount++;
      if (pos<=1) {
        AddNode_Start(_data);
        return;
      }
      int s = GetLinkedListSize(root);
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
      nodeCount--;
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
      nodeCount--;
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
      nodeCount--;
      if (pos<=1) {
        DeleteNode_Start();
        return;
      }
      int s = GetLinkedListSize(root);
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

    bool CheckForCycle(){
      if (hasCycle==true) {
        return true;
      }
      Node *slow = root, *fast = root;
      while (fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
          hasCycle = true;
          return true;
        }
      }
      return false;
    }

    // function to make cycle by connecting the last node to starting node
    void MakeCycle_Start(Node *root){
      if (root==nullptr){
        return;
      }
      if (CheckForCycle()==true){
        cout << "The linked list already has a cycle! Cannot add another (relevant code not available T_T)\n";
        return;
      }
      Node *p = root;
      while (p->next != nullptr){
        p = p->next;
      }
      p->next = root;
      hasCycle = true;
      cout << "Connected last node of Linked List to first node\n";
    }

    // function to make cycle by connecting the last node to ending node itself
    void MakeCycle_End(Node *root){
      if (root==nullptr){
        return;
      }
      if (CheckForCycle()==true){
        cout << "The linked list already has a cycle! Cannot add another (relevant code not available T_T)\n";
        return;
      }
      Node *p = root;
      while (p->next != nullptr){
        p = p->next;
      }
      p->next = p;
      hasCycle = true;
      cout << "Connected last node of Linked List to last node\n";
    }

    // function to make cycle by connecting the last node to the node at pos
    void MakeCycle_Pos(Node *root, int pos){
      if (root==nullptr){
        cout << "Linked List is empty!\n";
        return;
      }

      if (CheckForCycle()==true){
        cout << "The linked list already has a cycle! Cannot add another (relevant code not available T_T)\n";
        return;
      }

      if (pos <= 1){
        MakeCycle_Start(root);
        return;
      }
      if (pos >= GetLinkedListSize(root)){
        MakeCycle_End(root);
        return;
      }

      hasCycle = true;
      Node *p = root;
      while (p->next != nullptr){
        p = p->next;
      }
      Node *q = root;
      int count = 0;
      while (q!=nullptr){
        count++;
        if (count == pos){
          p->next = q;
          break;
        }
        q = q->next;
      }

      cout << "Connected last node of Linked List to node at pos '"<<pos<<"'\n";
    }

    // Function to remove cycle from linked list if present
    // "Floyd's Algorithm is used to remove the cycle"
    void RemoveCycle(Node *root){
      if (hasCycle==false){
        cout << "No Cycle was found in the Linked List!\n";
        return;
      }
      if (root == nullptr){
        cout << "Linked List is empty\n";
        return;
      }
      Node *slow=root, *fast = root;
      while (fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
          break;
        }
      }
      fast = root;
      int pos = 1;
      while (fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
        pos++;
      }
      slow->next = nullptr;
      hasCycle = false;
      cout << "Cycle found at pos '"<<pos+1<<"' has been removed!\n";
    }

    void PrintLinkedList() {
      // updating the nodeCount forcefully
      nodeCount = GetLinkedListSize(this->root);

      if (root == nullptr){
        cout << "Singular Linked List is EMPTY.\n";
        return;
      }
      if (hasCycle==true){
        cout << "Singular Linked List has a cycle present!\n";
        return;
      }
      Node *p = root;
      cout << "Printing the Singular Linked List having '"<<nodeCount<<"' nodes: ";
      while (p!=nullptr){
        cout << p->data << " ==> ";
        p = p->next;
        // if (p!=nullptr){
        //   cout << " --> ";
        // }
      }
      cout<< "NULL\n";
    }
};

Node* ReverseLinkedList_Iterative(Node *root){
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

// Reverse the linked list for k elements
// if k is 3 and linked list is like this -- 1,2,3,4,5,6,7,8,9,10,11
// then output is -- 3,2,1,6,5,4,9,8,7,11,10
Node* ReverseLinkedList_KNodes(Node *root, int k) {
  Node *prevPtr=nullptr, *currPtr=root, *nextPtr;;

  int count = 0;
  while (currPtr!=nullptr && count <k){
    nextPtr = currPtr->next;
    currPtr->next = prevPtr;
    prevPtr = currPtr;
    currPtr = nextPtr;
    count++;
  }

  if (nextPtr != nullptr){
    root->next = ReverseLinkedList_KNodes(nextPtr, k);
  }

  return prevPtr;
}

Node* AppendLastKNodesToStartOfLinkedList(Node *head, int k){
  if (head == nullptr || head->next == nullptr){
    return head;
  }
  int noOfNodes = GetLinkedListSize(head);
  if (k>=noOfNodes || k<=0){
    return head;
  }
  int count = 1;
  Node *oldHead = head, *newTail=head, *newHead, *oldTail;
  while (count != noOfNodes-k){
    count++;
    newTail = newTail->next;
  }
  newHead = newTail->next;
  oldTail = newHead;
  while (oldTail->next != nullptr){
    oldTail = oldTail->next;
  }

  head = newHead;
  newTail->next = nullptr;
  oldTail->next = oldHead;
  return head;
}

void JoinTwoLinkedListsAtEnd_withNewNode(LinkedList ll1, LinkedList ll2, int value){
  Node *temp = new Node(value);
  ll1.ConectNode(temp);
  ll2.ConectNode(temp);
  cout << "The Two Linked Lists jave been connected at the end with a new node with value:'"<<value<<"'\n";
}

Node* FindIntersectionPointOfTwoLinkedLists(LinkedList ll1, LinkedList ll2){
  Node *head1 = ll1.root, *head2 = ll2.root;
  int len1 = GetLinkedListSize(head1);
  int len2 = GetLinkedListSize(head2);
  int d=0;

  // adjusting so that ptr1 is the Linked List with larger size
  Node *ptr1, *ptr2;
  if (len1 > len2){
    d = len1 - len2;
    ptr1 = head1;
    ptr2 = head2;
  }
  else {
    d = len2 - len1;
    ptr1 = head2;
    ptr2 = head1;
  }

  while (d>0) {
    d--;
    ptr1 = ptr1->next;
    if (ptr1 == nullptr){
      return nullptr;
    }
  }

  while (ptr1!=nullptr && ptr2!=nullptr) {
    if (ptr1 == ptr2){
      return ptr1;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  return nullptr;
}

LinkedList MergeTwoSortedLinkedLists_Iterative(LinkedList ll1, LinkedList ll2){
  Node *ptr1=ll1.root, *ptr2=ll2.root;
  
  LinkedList mergedLL = LinkedList();
  Node *ptr3 = mergedLL.root;
  while (ptr1!=nullptr && ptr2!=nullptr){
    if (ptr1->data < ptr2->data){
      ptr3->next = ptr1;
      ptr1 = ptr1->next;
    }
    else {
      ptr3->next = ptr2;
      ptr2 = ptr2->next;
    }
    ptr3 = ptr3->next;
  }
  while (ptr1!=nullptr){
    ptr3->next = ptr1;
    ptr1 = ptr1->next;
    ptr3 = ptr3->next;
  }
  while (ptr2!=nullptr){
    ptr3->next = ptr2;
    ptr2 = ptr2->next;
    ptr3 = ptr3->next;
  }

  ptr3 = mergedLL.root->next;
  delete(mergedLL.root);
  mergedLL.root = ptr3;

  return mergedLL;
}

Node* MergeTwoSortedLinkedLists_Recursive(Node *head1, Node *head2){
  if (head1==nullptr){
    return head2;
  }
  if (head2==nullptr){
    return head1;
  }

  Node *newHead;
  if (head1->data < head2->data){
    newHead = head1;
    newHead->next = MergeTwoSortedLinkedLists_Recursive(head1->next, head2);
  }
  else {
    newHead = head2;
    newHead->next = MergeTwoSortedLinkedLists_Recursive(head1, head2->next);
  }

  return newHead;
}

Node* PutEvenPositionNodesAfterOddPositionNodes(Node *head){
  if (head==nullptr || head->next==nullptr || head->next->next==nullptr){
    return head;
  }
  Node *odd = head, *even=head->next, *evenStart=head->next;

  while (odd->next!=nullptr && even->next!=nullptr){
    odd->next = even->next;
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }
  odd->next = evenStart;
  return head;
}

void test1(){
  // vector<int> arr = {-2,4,5,-3,9,34,1,0,45,32};
  // LinkedList ll1 = LinkedList(arr);
  // ll1.PrintLinkedList();
  // ll1.AddNode_End(78);
  // ll1.PrintLinkedList();
  // ll1.AddNode_Start(-42);
  // ll1.PrintLinkedList();
  // ll1.AddNode_Pos(18, 5);
  // ll1.PrintLinkedList();
  // ll1.DeleteNode_Start();
  // ll1.PrintLinkedList();
  // ll1.DeleteNode_Pos(7);
  // ll1.PrintLinkedList();
  // cout << "Reversing the Linked List using Iterative method!\n";
  // ll1.root = ReverseLinkedList_Iterative(ll1.root);
  // ll1.PrintLinkedList();
  // cout << "Reversing the Linked List using Recursive method!\n";
  // ll1.root = ReverseLinkedList_recursive(ll1.root);
  // ll1.PrintLinkedList();
  // cout << "Reversing the K Nodes of the Linked List!\n";
  // ll1.root = ReverseLinkedList_KNodes(ll1.root, 3);
  // ll1.PrintLinkedList();
  // ll1.MakeCycle_Pos(ll1.root, 4);
  // ll1.PrintLinkedList();
  // ll1.RemoveCycle(ll1.root);
  // ll1.PrintLinkedList();
  // ll1.root = AppendLastKNodesToStartOfLinkedList(ll1.root, 5);
  // cout << "Appending the last 5 Nodes of the Linked List to the start\n";
  // ll1.PrintLinkedList();
}

void test2() {
  // LinkedList ll1 = LinkedList({1,2,3});
  // LinkedList ll2 = LinkedList({7,6,5});
  // JoinTwoLinkedListsAtEnd_withNewNode(ll1, ll2, 4);
  // ll1.PrintLinkedList();
  // ll2.PrintLinkedList();
  // ll1.AddNode_End(0);
  // ll1.AddNode_End(8);
  // ll1.AddNode_End(9);
  // ll1.AddNode_End(11);
  // ll1.PrintLinkedList();
  // ll2.PrintLinkedList();
  // Node *intersectionNode = FindIntersectionPointOfTwoLinkedLists(ll1, ll2);
  // if (intersectionNode != nullptr){
  //   cout << "Intersection node found with value: "<<intersectionNode->data<<endl;
  // }
  // else {
  //   cout << "No intersection node has been found!";
  // }
}

void test3() {
  LinkedList ll1 = LinkedList({1,2,7,9});
  ll1.PrintLinkedList();
  LinkedList ll2 = LinkedList({0,3,5,8});
  ll2.PrintLinkedList();
  Node *mergedLL2 = MergeTwoSortedLinkedLists_Recursive(ll1.root, ll2.root);
  PrintLinkedList(mergedLL2);
  // LinkedList mergedLL1 = MergeTwoSortedLinkedLists_Iterative(ll1, ll2);
  // mergedLL1.PrintLinkedList();
}

void test4() {
  LinkedList ll1 = LinkedList({1,2,3,4,5,6,7,8});
  ll1.PrintLinkedList();
  Node *alteredNode = PutEvenPositionNodesAfterOddPositionNodes(ll1.root);
  PrintLinkedList(alteredNode);
}

int main() {
  // test1();
  // test2();
  // test3();
  test4();
}