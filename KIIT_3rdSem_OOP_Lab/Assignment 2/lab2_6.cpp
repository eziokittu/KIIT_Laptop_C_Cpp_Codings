/*KIIT OOP LAB Question 2-6
Create a class which stores id, name, age and basic salary of an employee.
Input data for n number of employees. Calcualte the gross salary of all the employees
and display it along with all the other details in a tabular form.
[
    Gross Salary = Basic Salary + DA + HRA
    DA = 80% of Basic Salary
    HRA = 10 % of Basic Salary
]
*/

#include <iostream>
using namespace std;

class Employee{
    private:
        int id;
        string name;
        int age;
        float salary;
        float gross;
    public:
        void GetData(){
            cout << "Enter id: ";
            cin >> id;
            cout << "Enter name: ";
            getline(cin >> ws, name);
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter salary: ";
            cin >> salary;
        }
        void CalcGrossSal(){
            gross = (1.9*salary);
            /*
                da = (80/100)*salary
                hra = (10/100)*salary
                salary += da + hra
            */
        }
        void Display(){
            cout << "\nEmployee: "<<name << ", ID: "<<id << ", age: " <<age <<", Gross Salary: "<<gross;
        }
};

int main(){
    // Getting the number of employees
    cout << "\nHow many Employees: ";
    int n;
    cin >> n;

    Employee emp[n];

    // Getting data for all employees
    for (int i=0; i<n; i++){
        cout << "Enter details for employee "<< i+1 << endl;
        emp[i].GetData();

        // calculatting gross salary in same loop
        emp[i].CalcGrossSal();
    }

    // Displaying details of all employees
    cout << "\nDispalying details fo all employees: ";
    for (int i=0; i<n; i++){
        emp[i].Display();
    }
}