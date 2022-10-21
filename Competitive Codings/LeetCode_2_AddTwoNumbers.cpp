// LeetCode Problem 2 0 Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *head = nullptr;

// function to get the length of the linked list
int listLength(ListNode *head){
    int count = 1;
    ListNode *temp = head;
    if (temp== NULL) return 0;
    else{
        while (temp->next != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
}

ListNode *ReverseLinkedList(ListNode *head){
    if (head==nullptr){
        printf("No linked list exists");
        exit(1);
    }
    ListNode *p=nullptr, *q=nullptr, *r=head;
    while(r){
        q=r->next;
        r->next=p;
        p=r;
        r=q;
    }
    head=p;
    return head;
}
  
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // after reversing the 2 linked lists
    l1 = ReverseLinkedList(l1);
    l2 = ReverseLinkedList(l2);

    ListNode *l3;
    
    int length1 = listLength(l1);
    int length2 = listLength(l2);
    int l;

    if (length1 > length2 ? l=length1 : l=length2);
    ListNode *p1 = l3;
    int temp_l = l;
    // adding 0 to val of all nodes in l3
    while (temp_l>=0){
        ListNode *temp;
        temp = (ListNode*) malloc (sizeof(ListNode));
        temp_l--;
        temp->val=0;
    }
    ListNode *p=l3;
    int carry = 0;
    while (l>=0){
        int sum;
        if (l1!=nullptr && l2!=nullptr)
            sum += l1->val + l2->val + carry;
        else if (l1!=nullptr)
            sum += l1->val + carry;
        else if (l2!=nullptr)
            sum += l2->val + carry;
        else 
            sum += carry;

        if (sum>9){
            sum = sum-10;
            carry = 1;
        }

        p->val = sum;
        p = p->next;
        l--;
    }
}

int main(){
    int num1[] = {4,8,9};
    int num2[] = {1,0,7,1,3};
    for (int i=0; num1[i]!='\0'; i++){
        ListNode *temp;
        temp = (ListNode*) malloc (sizeof(ListNode));
        temp->val=num1[i];
        if (head==nullptr){
            head = temp;
        }
        else {
            
        }
    }
}
