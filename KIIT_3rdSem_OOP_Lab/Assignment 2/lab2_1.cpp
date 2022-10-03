// KIIT OOP LAB - Question 2-1
// WAP to display the message "Hello" followed by your name on screen

#include <iostream>
using namespace std;

int main(){
    string name;
    cout << "Enter your name : ";
    getline(cin >> ws, name); // for string input, cin>>ws takes the white space as input
    cout<<"\nHello "<< name <<"\n";
    return 0;
}