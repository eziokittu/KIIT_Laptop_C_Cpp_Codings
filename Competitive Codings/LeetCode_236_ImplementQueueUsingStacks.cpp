// Leetcode Problem 236 - Implement Queue using Stack
// https://leetcode.com/problems/implement-queue-using-stacks/

#include <iostream>

using namespace std;

class MyQueue {
public:
    int arr1[100];
    int arr2[100];
    int size1;
    int size2;

    MyQueue() {
        size1 = 0;
        size2 = 0;
        // fill(arr1, arr1+size1, 0);
        for (int i=0; i<100; i++){
            arr1[i]=0;
            arr2[i]=0;
        }
    }
    
    void push(int x) {
        arr1[size1++]=x;
    }
    
    int pop() {
        if (size2>0){
            return arr2[--size2];
        }
        else{
            for (int i=size1-1; i>=0; i--){
                arr2[size2++]=arr1[i];
            }
            size1=0;
            return arr2[--size2];
        }
        return -1;
    }
    
    int peek() {
        if (size2>0){
            return arr2[size2-1];
        }
        else{
            for (int i=size1-1; i>=0; i--){
                arr2[size2++]=arr1[i];
            }
            size1=0;
            return arr2[size2-1];
        }
        return -1;
    }
    
    bool empty() {
        if (size1==0 && size2==0){
            return true;
        }
        return false;
    }
    
    void display(){
        cout <<"\nDisplaying arr1:";
        for (int i=0; i<size1; i++){
            cout << " "<<arr1[i];
        }
        if (size1==0) cout<<" NONE";
        cout <<"\nDisplaying arr2:";
        for (int i=0; i<size2; i++){
            cout << " "<<arr2[i];
        }
        if (size2==0) cout<<" NONE";
    }
};

int main()
{
    MyQueue *q = new MyQueue();
    q->display();
    q->push(1);
    q->display();
    q->push(2);
    q->display();
    cout << "\nPeek(): "<<q->peek();
    cout << "\nPop(): "<< q->pop();
    q->display();
    q->push(3);
    cout << "\nPeek: "<< q->peek();

    return 0;
}