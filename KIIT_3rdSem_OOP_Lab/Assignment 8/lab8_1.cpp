// OOPs LAB Assignment 8
// Q1) WAP to overload following operators for class distance, which 
// stores the distance in feet and inches. 
//      a) Binary + to 
//          -add two objects (D3=D1+D2) 
//          -Add an object to an integer, where the integer should 
//           be added to the inches value ( D2=4+D1) 
//      b) Unary -

#include <iostream>
using namespace std;

class Distance {
    public:
        float feet;
        float inches;
        Distance(){
            feet = 0;
            inches = 0;
        }
        Distance(float f, float i){
            feet = f;
            inches = i;
        }
        Distance(const Distance& d){
            feet = d.feet;
            inches = d.inches;
        }
        Distance operator+(Distance &d1){ // add two objects (D3=D1+D2)
            return (Distance){this->feet + d1.feet, this->inches + d1.inches};
        }
        Distance operator+(int a){ // add integer to object (D3=4+D2)
            return (Distance){this->feet, this->inches + a};
        }
        Distance operator-(){ // D3 = -D3
            return (Distance){-this->feet, -this->inches};
        }
        void GetData(){
            cout << "\n----Enter distance data ----";
            cout << "\nFeet: ";
            cin >> feet;
            cout << "Inches: ";
            cin >> inches;
        }
        void Display(){
            inches += ((feet-int(feet)) * 12); // taking only integer part from feet
            feet += int(inches/12);
            inches = (inches - int(inches)) + int(inches)%12; // making inches value less than 12
            printf("\nDistance is %d feet and %.2f inches",int(feet), inches);
        }
};

int main(){
    Distance d1;
    d1.GetData();
    Distance d2;
    d2.GetData();
    Distance d3 = d1 + d2; // binary operator overloaded (object + object)
    Distance d4 = d1 + 10; // binary operator overloaded (object + integer)
    Distance d5 = -d4; // Unary operator overloaded

    d1.Display();
    d2.Display();
    d3.Display();
    d4.Display();
    d5.Display();
    return 0;
}