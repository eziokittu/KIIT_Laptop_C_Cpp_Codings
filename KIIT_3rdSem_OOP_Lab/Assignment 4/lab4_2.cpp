// OOP LAB Assignment 4
// Q2) Create two classes which stores distance in feet, inches
// and meter, centimeter format respectively. Write a function 
// which compares distance in object of these classes and 
// display the larger one

#include <iostream>
using namespace std;

// Declaring 2 classes
class Dist_m_cm;
class Dist_f_in;

// Defining 2 classes
class Dist_m_cm{
    private:
        float m;
        float cm;
    public:
        void SetData(){
            cout << "\nEnter data for Distance -";
            cout << "\nMeter: "; cin >> m;
            cout << "Centimeter: "; cin >> cm;
        }
        friend void CmpDistAndDisplay(Dist_m_cm &a, Dist_f_in &b);
};
class Dist_f_in{
    private:
        float f;
        float in;
    public:
        void SetData(){
            cout << "\nEnter data for Distance -";
            cout << "\nFeet: "; cin >> f;
            cout << "Inches: "; cin >> in;
        }
        friend void CmpDistAndDisplay(Dist_m_cm &a, Dist_f_in &b);
};

// Defining the friend function common to both classes;
void CmpDistAndDisplay(Dist_m_cm &a, Dist_f_in &b){
    // 1 meter = 3.28084 feet
    // 0.01 m = 1 cm = 0.328084 * 12 inches
    // 1 cm = 3.93701
    float cm = a.cm + a.m*100;
    float in = b.in + b.f*12;
    cout << "\nMax Distance = ";
    if (cm*3.93701 <= in) cout<<b.f<<" feet, "<<b.in<<" inches";
    else cout<<a.m<<" meter, "<<a.cm<<" centimeter";
}

int main()  
{  
    Dist_m_cm a;  
    Dist_f_in b;  
    a.SetData();  
    b.SetData();  
    CmpDistAndDisplay(a,b);  
    return 0;  
}  