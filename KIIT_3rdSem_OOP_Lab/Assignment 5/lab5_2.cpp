// OOPs LAB Assignment 5
// Q2) Create a class which stores time in hh:mm format. Include all
// the constructors. The parameterized constructor should initiate the
// minute value to zero, if it it not provided.

#include <iostream>
using namespace std;

class Time{
    int hh;
    int mm;
    public:
        // Default Constructor
        Time (){
            hh = 0;
            mm = 0;
        }

        // Parameterised Contructors
        // Time (float i){
        //     hh = 0;
        //     imag = i;
        //     AddCount();
        // }
        Time (int _hh, int _mm=0){
            hh = _hh;
            mm = _mm;
        }

        // Copy Constructors
        Time (const Time &t){
            hh = t.hh;
            mm = t.mm;
        }

        void Display(){
            cout <<endl;
            if (hh<0 || mm<0){
                cout <<"Not a valid time - ";
            }
            cout << "Time: "<<(hh+mm/60)%24<<":"<<mm%60;;
        }
};

int main(){
    Time t1;
    Time t2(51);
    Time t3(-7,56);
    Time t4(47, 94);
    Time t5(t4);
    Time t6(24, 180);

    // Displaying
    t1.Display();
    t2.Display();
    t3.Display();
    t4.Display();
    t5.Display();
    t6.Display();
}