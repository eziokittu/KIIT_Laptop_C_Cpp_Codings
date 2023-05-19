#include <iostream>

using namespace std;

string DecimalToAnyBaseConvertor(int num, int base){
    string s = "";
    while (num>0){
        int quotient = num/base;
        int rem = num - base*quotient;
        if (rem<10){
            s=(char)(rem+'0')+s;
        }
        else{
            s=(char)(rem-10+'A')+s;
        }
        num = quotient;
    }
    return s;
}

int main()
{
    cout << "\nEnter a number (Decimal) to convert: ";
    int num;
    cin >> num;
    cout << "Enter the base: ";
    int base;
    cin >> base;
    cout << DecimalToAnyBaseConvertor(num, base);
    
    main();
}