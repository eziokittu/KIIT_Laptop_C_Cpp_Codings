#include <iostream>

using namespace std;

int main(){

    // Delaration
    int i;
    float f;
    double d;
    char c;
    bool b;

    short int si;
    long int li;
    long long int lli;
    unsigned long long int ulli;

    // Initialization
    i = 13;
    f = 45.874;
    d = 29.89435795675;
    c = 'f';
    b = true;

    // Using 'sizeof' method to know their sizes
    cout << "Size of Integer i : " << sizeof(i) << endl;
    cout << "Size of Float f : " << sizeof(f) << endl;
    cout << "Size of Double d : " << sizeof(d) << endl;
    cout << "Size of Char c : " << sizeof(c) << endl;
    cout << "Size of Boolean b : " << sizeof(b) << endl;

    cout << "Size of short Integer si : " << sizeof(si) << endl;
    cout << "Size of long Integer li : " << sizeof(li) << endl;
    cout << "Size of long long Integer lli : " << sizeof(lli) << endl;
    cout << "Size of Unsigned long long Integer ulli : " << sizeof(ulli) << endl;
}