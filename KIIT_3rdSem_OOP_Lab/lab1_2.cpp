// WAP to input name, roll number, and marks in 5 subjects for a student and display it.

#include <iostream>
using namespace std;

int noOfStudents;

// structure defination of Student
typedef struct {
    string name;
    int roll;
    float marks[10]; // marks of 5 subjects out of 100
}Student;

// function to print total marks and percentage of a student
void Print_TotalMarksAndPercentage(Student s){
    float total; // total marks
    for (int i=1; i<=5; i++){
        total += s.marks[i+1];
    }
    cout << "\nTotal marks for Student : " << s.name << " is " << total;
    cout << "\nPercentage is : " << ((total*100)/500);
}

// function to display details of a student with a given roll number
//void Print_DetailsOfStudentWithRoll(Student *s, int roll){
    //for (int i=0; i<noOfStudents)
    //if (*s.)
//}

// Driver Code Starts here
int main (){
    
    // Getting the number of students
    cout << "How many students : ";
    cin >> noOfStudents;
    
    // Getting all the details for all students
    Student s[noOfStudents];
    for (int i=0; i<noOfStudents; i++){
        cout << "\n----- For student " << i+1 << " -----\n";
        cout << "Name : ";
        getline(cin >> ws, s[i].name);
        cout << "Roll no. : ";
        cin >> s[i].roll;
        cout << "Enter marks for the subjects (Maths, Physics, Chemistry, Biology, English) respectively :\n";
        for (int j=0; j<5; j++){
            cin >> s[i].marks[j]; 
        }
        for (int j=0; j<5; j++){
            cout << s[i].marks[j]; 
        }
    }
    
    // Displaying total marks and percentage of all students
    for (int i=0; i<noOfStudents; i++){
        Print_TotalMarksAndPercentage(s[i]);
    }   
}