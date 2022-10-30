// Q6) Create a class which stores employee name, id and salary. Derive two
// classes from 'Employee' class: 'Regular' and 'Part-Time'. The regular stores
// DA, HRA, Basic Salary. The part time class stores the number of hours and
// pay per hour. Calculate the salary of a reglar and a part-time employee.

#include <iostream>
using namespace std;

class Employee{
    public:
        string name;
        int id;
        float salary;
        void GetDetails(){
            cout << "\nEnter name : ";
            getline (cin>>ws, name);
            cout <<"Enter ID : ";
            cin >> id;
        }
        void PrintSalary(){
            cout << "\nThe salary of the employee ["<<name;
            cout << ", Emp ID : "<< id <<"] is " << salary;
        }
};

class Regular: public Employee{
    float DA, HRA, Basic;
    public:
        void CalculateSalary(){
            cout << "\nFor Employee - "<<name;
            cout << "\nWhat is basic salary? - ";
            cin >> Basic;
            // DA = 80% of Basic Salary = 0.8 * basic
            DA = .8 * Basic;
            // HRA = 10% of basic Salary = 0.1 * basic
            HRA = .1 * Basic;
            // total = basic + 0.9*basic = 1.9 * basic
            salary = Basic + DA + HRA;
        }
};

class Part_Time: public Employee{
    float payPerHour;
    float noOfHours;
    public:
        void CalculateSalary(){
            cout << "\nFor Employee - "<<name;
            cout <<"\nWhat is the rate of pay per hour? - ";
            cin >> payPerHour;
            cout <<"How many no. of hours worked? - ";
            cin >> noOfHours;
            salary = noOfHours * payPerHour;   
        }
};

int main(){
    Regular emp1;
    Part_Time emp2;

    emp1.GetDetails();
    emp2.GetDetails();

    emp1.CalculateSalary();
    emp2.CalculateSalary();

    emp1.PrintSalary();
    emp2.PrintSalary();

    return 0;
}