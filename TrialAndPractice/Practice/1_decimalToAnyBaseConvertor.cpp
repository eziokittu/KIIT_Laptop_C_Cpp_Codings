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
    printf("Converted to base %d: ", base);
    return s;
}

int main()
{
    cout << "Enter a number (Decimal) to convert: ";
    int num;
    cin >> num;

    // break
    if (num==0) return 0;

    cout << "Enter the base: ";
    int base;
    cin >> base;
    cout << DecimalToAnyBaseConvertor(num, base);
    
    printf("\n\nEnter num as '0' to exit!\n");
    main();
}

// OUTPUT 
// Enter a number (Decimal) to convert: 5
// Enter the base: 5
// Converted to base 5: 10

// Enter num as '0' to exit!
// Enter a number (Decimal) to convert: 2
// Enter the base: 2
// Converted to base 2: 10

// Enter num as '0' to exit!
// Enter a number (Decimal) to convert: 100
// Enter the base: 100
// Converted to base 100: 10

// Enter num as '0' to exit!
// Enter a number (Decimal) to convert: 59
// Enter the base: 18
// Converted to base 18: 35

// Enter num as '0' to exit!
// Enter a number (Decimal) to convert: 15
// Enter the base: 15
// Converted to base 15: 10

// Enter num as '0' to exit!
// Enter a number (Decimal) to convert: 15 
// Enter the base: 14
// Converted to base 14: 11

// Enter num as '0' to exit!
// Enter a number (Decimal) to convert: 15
// Enter the base: 16
// Converted to base 16: F

// Enter num as '0' to exit!
// Enter a number (Decimal) to convert: 20
// Enter the base: 35
// Converted to base 35: K

// Enter num as '0' to exit!
// Enter a number (Decimal) to convert: 100
// Enter the base: 34
// Converted to base 34: 2W

// Enter num as '0' to exit!