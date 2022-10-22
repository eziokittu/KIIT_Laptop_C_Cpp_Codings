// OOPs LAB 6 -
// Q1) WAP to demonstrate all types of inheritance

#include <iostream>
using namespace std;

class Parent1{
    public: string p1="\nParent1";
};

class Parent2{
    public: string p2="\nParent2";
};

// single level inheritance
class Child1: public Parent1{
    public: string c1="\nChild1";
};

// multiple inheritance
class Child2: public Parent1, public Parent2{
    public: string c2="\nChild2";
};

// both are also under hierarchical inheritance since they are derived from same parent class child1
// multi level inheritance
class GrandChild1_1: public Child2{
    public: string gc1 = "\nGrandChild1";
};
// multi level inhertance
class GrandChild1_2: public Child2{
    public: string gc2 = "\nGrandChild2";
};

// since grandChld1_1 is both multilevel, hierarchical, it is also HYBRID inheritance

int main(){
    cout << "\nDemonstrating all types of Inheritance";
    Child1 child1;
    cout << "\n(Single Inheritance) Child 1 has prooerties: "<<child1.p1<<child1.c1;
    Child2 child2;
    cout << "\n\n(Multiple Inheritance) Child 2 has prooerties: "<<child2.p1<<child2.p2<<child2.c2;

    GrandChild1_1 grand1;
    cout << "\n\n(Multi level + Hiearchical Inheritance) GrandChild 1 has prooerties: "<<grand1.p1<<grand1.p2<<grand1.c2<<grand1.gc1;

    GrandChild1_2 grand2;
    cout << "\n\n(Multi level + Hiearchical Inheritance) GrandChild 2 has prooerties: "<<grand2.p1<<grand2.p2<<grand2.c2<<grand2.gc2;

    return 0;
}