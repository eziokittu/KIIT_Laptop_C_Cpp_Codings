// OOPs LAB Assignment - 10
// Q4) WAP to throw and handle 'division by zero' exception

#include <iostream>
using namespace std;

void func(){
    float a, b;
    cout << "\nEnter value for a nd b : ";
    cin >> a >> b;
    cout << a << "/" << b << " = ";
    try{  
        cout << a/b <<"---";
    }
    catch(const std::exception& e){
        cout << "[Division by Zero Exception]";
    }
}

int main(){
    func();
    func();
    func();

    return 0;
}