// OOP LAB Assignment 4
// Q4) Create a class which stores name, roll number and total marks
// for a student. Input data for n students. Find the average marks
// scored by n students, store it as a data member of the class and
// display it using a function which may be called without object

# include <iostream>
using namespace std;

class Student;

class Student{
    private:
        int roll;
        string name;
        float marks;
        static float avg;
        static int count;
    public:
        void GetData(){
            printf("\n-- For student %d --\n",GetCount());
            cout<<"Name: "; getline(cin>>ws, name);
            cout<<"Roll: "; cin >> roll;
            cout<<"Marks: "; cin >> marks;
            AddCount();
        }
        static int GetCount(){ return count;}
        static void AddCount(){ ++count;}
        static void ShowAverage(){
            cout << "\nAverage marks of all students is: "<<avg;
        }
        friend void GetAverage(Student *s);
};

void GetAverage(Student *s){
    float sum;
    for (int i=0; i<Student::GetCount(); i++){
        sum += s[i].marks;
    }
    Student::avg = sum/Student::GetCount();
}

int Student::count;
float Student::avg;

int main(){
    int n;
    cout << "How many students? - "; cin >> n;
    Student s[n];
    for (int i=0; i<n; i++){
        s[i].GetData();
    }
    GetAverage(&s[0]);
    Student::ShowAverage();

    return 0;
}