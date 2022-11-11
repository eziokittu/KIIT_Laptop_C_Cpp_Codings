// OOPS LAB Assignment - 8
// Q2) Create a class to store an integer array. Overload insertion and 
// extraction operator to input and display the array elements.

#include <iostream>
using namespace std;

class Array{
    public: 
        int a;
        friend istream& operator>>(istream &input, Array& arr);
        friend ostream& operator<<(ostream &output, Array& arr);
};

// Overloading stream insertion operator
istream& operator >> (istream &input, Array& arr){
    input >> arr.a;
    return input;
}

// Overloading stream extraction operator
ostream& operator << (ostream &output, Array& arr){
    output << arr.a;
    return output;
}

int main(){
    Array arr[10];
    for (int i=0; i<4; i++){
        cout << "Enter arr["<<i<<"] : ";
        cin >> arr[i];
    }
    cout << "\nPrinting the array: ";
    for (int i=0; i<4; i++){
        cout << arr[i];
        cout << " ";
    }
    return 0;
}