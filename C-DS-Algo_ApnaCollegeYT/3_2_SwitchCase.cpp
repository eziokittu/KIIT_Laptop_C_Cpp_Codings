#include <iostream>
using namespace std;

int main(){
    int num1, num2;
    cout << "Enter 1st number : ";
    cin >> num1;
    cout << "Enter 2nd number : ";
    cin >> num2;
    char op;
    cout << "Enter an operator (+, -, /, *) : ";
    cin >> op;

    switch (op)
    {
    case '+':
        cout << "Addition of " <<num1 << " and " <<num2 << " = " << num1+num2;
        break;
    case '-':
        cout << "Subtraction of " <<num1 << " and " <<num2 << " = " << num1-num2;
        break;
    case '/':
        cout << "Division of " <<num1 << " and " <<num2 << " = " << (float)num1/(float)num2;
        break;
    case '*':
        cout << "Multiplication of " <<num1 << " and " <<num2 << " = " << num1*num2;
        break;
    default:
        cout << "Wrong operator given!";
        break;
    }
}