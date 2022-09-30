/*
KIIT OOP Lab (21.09.2022): Question 3
Q) WAP to enter id, name, age and basic salary of n number of employees. Calculate the
gross salary of all the employees and display it along with all the other details in
a tabular form, using pointer to structure
    [
    Gross salary = Basic Salary + DA + HRA
    DA = 80% of Basic Salary
    HRA = 10% of Basic Salary
    ]
*/

#include <iostream>
using namespace std;

int noOfEmployees; // global declaration

// structure defination of a Student
typedef struct {
    int id;
    string name;
    int age;
    float salary;
    float gross;
}Employee;

// function to display details of all employees using pointer to struct
void DisplayDetails(Employee *ptr){
    for (int i=0; i<noOfEmployees; i++){
        cout << "\nEmployee: "<<ptr->name << ", ID: "<<ptr->id << ", age: " <<ptr->age;
        cout << "\nGross Salary: "<<ptr->gross;
        ptr++;
    }
}

int main()
{
    // getting the number of employees
    cout << "\nEnter the no. of employees : ";
    cin >> noOfEmployees;

    Employee e1[noOfEmployees];
    Employee *ptr = e1;

    // Enter details
    for (int i=0; i<noOfEmployees; i++){
        cout << "---- Enter details for employee " << i+1 << " ----";
        cout << "\nEnter name of employee : ";
        getline(cin>>ws, e1[i].name);
        cout << "Enter age : ";
        cin >> e1[i].age;
        cout << "Enter employee ID : ";
        cin >> e1[i].id;
        cout << "Enter salary : ";
        cin >> e1[i].salary;
        
        // Calculate Salary of each employee
        float _gross;
        _gross = (ptr->salary) + (0.8*(ptr->salary)) + (0.1*(ptr->salary));
        ptr->gross = _gross;
    }

    // Display details of all employees
    DisplayDetails(ptr);
    
    return 0;
}

