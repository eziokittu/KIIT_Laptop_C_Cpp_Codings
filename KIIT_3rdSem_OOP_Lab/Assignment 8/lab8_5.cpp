// OOPs LAB Assignment - 8
// Q5) WAP to add two objects of time class. Overload the operator
// ‘==’ to compare two objects and display whether they are equal
// or not. Overload the assignment operator.

#include <iostream>
using namespace std;

class Time{
    int hh, mm, ss;
    public:
        Time (){
            hh = 0;
            mm = 0;
            ss = 0;
            NormalTime();
        }
        Time (int h, int m, int s){
            hh = h;
            mm = m;
            ss = s;
            NormalTime();
        }
        int operator==(Time &t){
            if (
            this->hh == t.hh and
            this->mm == t.mm and
            this->ss == t.ss
            ) return 1;
            else return 0;
        } 
        Time& operator=(Time &t){ 
            return t;
        } 
        void NormalTime(){
            mm += ss/60;
            ss = ss%60;
            hh += mm/60;
            mm = mm%60;
            hh = hh % 24;
        }
        void Display(){
            printf("\nTime is : %d:%d:%d", hh, mm, ss);
        } 
};

int main(){
    Time t1(2,120,60);
    t1.Display();
    Time t2(3,61,0);
    t2.Display();
    if (t1 == t2){
        cout << "\nBoth the times are equal";
    }
    else cout << "\nThe time is not same";
    Time t3(30,59,58);
    t3.Display();
    Time t4 = t3;
    t4.Display();
}