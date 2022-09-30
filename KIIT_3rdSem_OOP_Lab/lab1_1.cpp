// WAP to input name, roll number, and marks in 5 subjects for a student and display it.

#include <iostream>
using namespace std;

int main (){
    // Declaring variables
    int roll;
    string name;
    float marks[5]; // marks for 5 subjects
    
    // Getting all the details
    cout << "Enter name and roll no. of the student : \n";
    getline(cin >> ws, name);
    cin >> roll;
    cout << "Enter marks for the subjects (Maths, Physics, Chemistry, Biology, English) respectively :\n";
    for(int i=0; i<5; i++){
        cin >> marks[i];
    }
    
    // Displaying all the details of the student
    cout << "\nName : "<< name << ", Roll : " << roll;
    cout << "\nMarks in all 5 subjects :";
    for (int i=0; i<5; i++){
        cout << " " << marks[i];
    }
}