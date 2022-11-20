// OOPs LAB Assignment - 10
// Q4) WAP to throw and handle 'division by zero' exception

#include <iostream>
using namespace std;

void func(){
    float a, b;
    cout << "\nEnter value for a and b : ";
    cin >> a >> b;
    cout << a << "/" << b << " = ";
    
    try{  
        // if condition used to get a custom output otherwise div by 0 
        // gives inf because new C++ compiler already handles the exception
        if (b==0){
            cout << "[Exception occurred]";
            return;
        }
        cout << a/b ;
    }
    // unused code because new C++ compliers handle the exception by itself
    catch (exception e) {
        cout << "Exception occurred" << endl << e.what();
    }
}

int main(){
    func();
    func();
    func();

    return 0;
}