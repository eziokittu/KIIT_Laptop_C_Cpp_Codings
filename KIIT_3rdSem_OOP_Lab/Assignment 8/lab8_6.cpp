// OOPs LAB Assignment - 8
// Q6) WAP  to add two objects of distance class. Overload the operator
// ‘>’ to compare two objects and return the object with larger time
// value and display it. Overload the ‘==’ operator to compare and 
// display whether two given objects contain same distance value.

#include <iostream>
using namespace std;

class Distance {
    public:
        float feet;
        float inches;
        Distance(){
            feet = 0;
            inches = 0;
        };
        Distance(float f, float i){
            feet = f;
            inches = i;
        }
        Distance(const Distance& d){
            feet = d.feet;
            inches = d.inches;
        }
        Distance operator+(Distance &d1){
            return (Distance){this->feet + d1.feet, this->inches + d1.inches};
        }
        Distance operator>(Distance &d1){
            if (this->feet*12+this->inches > d1.feet*12+d1.inches){
                return *this;
            }
            else return d1;
        }
        bool operator==(Distance &d1){
            this->NormalDistance();
            d1.NormalDistance();
            if (this->feet == d1.feet && this->inches == d1.inches)
                return true;
            else
                return false;
        }
        void NormalDistance(){
            inches += ((feet-int(feet)) * 12); // taking only integer part from feet
            feet += int(inches/12);
            inches = (inches - int(inches)) + int(inches)%12; // making inches value less than 12
        }
        friend void Display(Distance *d);
};

void Display(Distance d){
    d.NormalDistance();
    printf("Distance is %d feet and %.2f inches",int(d.feet), d.inches);
}

int main(){
    Distance d1(5.75, 28.5);
    cout << "\nd1 -- ";
    Display(d1);

    Distance d2(10.5,10);
    cout << "\nd2 -- ";
    Display(d2);

    Distance d3 = d1+d2; // operator '+' overloaded
    cout << "\nd3 -- ";
    Display(d3);

    cout << "\nWhich is greater d1 or d3 -- ";
    Display(d2>d3); // operator '>' overloaded

    cout << "\nd3==d1? -- ";
    if (d3==d1) // operator '++' overloaded
        cout << "True";
    else 
        cout << "False";

    return 0;
}