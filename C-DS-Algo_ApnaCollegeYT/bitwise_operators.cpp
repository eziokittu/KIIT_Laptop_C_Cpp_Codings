// bitwise operators
/*
1. Bitwise NOT operator (~) - unitary operator - complements the bits
2. Bitwise AND operator (&)
3. bitwise OR operator (|)
4. bitwise Shift left operator (<<)
5. bitwise Shift Right operator (>>)
*/
# include <iostream>
using namespace std;

int main(){

    cout <<"\n---- Bitwise NOT operator ----\n";
    int a = 10;
    cout << "a = "<<a <<endl;
    cout << "~a = "<<(~a);

    cout <<"\n\n---- Bitwise AND operator ----\n";
    // compares to bits parallaly for 2 numbers
    // and does the AND operation
    a = 5;      //0101
    int b = 9;  //1001
    cout << "a = "<<a <<", b="<<b<<endl;
    cout << "a&b = "<<(a&b);

    cout <<"\n\n---- Bitwise OR operator ----\n";
    // compares to bits parallaly for 2 numbers
    // and does the AND operation
    a = 10; //1010
    b = 7;  //0111
    cout << "a = "<<a <<", b="<<b<<endl;
    cout << "a|b = "<<(a|b);

    cout <<"\n\n---- Left Shift operator ----\n";
    a = 10; //1010
    cout << "a = "<<a <<endl;
    cout << "a<<2 = "<<(a<<2);

    cout <<"\n\n---- Right Shift operator ----\n";
    a = 10; //1010
    cout << "a = "<<a <<endl;
    cout << "a>>2 = "<<(a>>2);

    return 0;
}