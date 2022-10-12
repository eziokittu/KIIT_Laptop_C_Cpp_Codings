// Assignment 3
// Q3) WAP which displays a given character, n number of times, using
// a function. When the n value is not provided, it should print the
// given character 80 times. When both the character and n value is
// not provided, it should print '*' character 80 times. [ Write the
// program in 2 ways : 
// i) using function overloading
// ii) using default arguements.]

#include <iostream>
using namespace std;

// Part 1 is done using function overloading
void Part1_Display(char c, int n){
    cout<<endl;
    for(int i=0; i<n; i++) cout << c;
}
void Part1_Display(char c){
    cout<<endl;
    for(int i=0; i<80; i++) cout << c;
}
void Part1_Display(){
    cout<<endl;
    for(int i=0; i<80; i++) cout << '*';
}

// Part 2 is done using default arguements
void Part2_Display(char c='*', int n=80){
    cout<<endl;
    for(int i=0; i<n; i++) cout << c;
}

int main(){
    int n;
    char c;
    cout << "Enter a character : "; cin >> c;
    cout << "Enter no. of times to print : "; cin >> n;

    cout << "\nPrinting using Function Overloading -";
    Part1_Display(c, n);
    Part1_Display(c);
    Part1_Display();

    cout << "\nPrinting using default Arguements -";
    Part2_Display(c, n);
    Part2_Display(c);
    Part2_Display();

    return 0;
}