# include <iostream>
using namespace std;

class Student{
    private:
        string name;
        int roll;
        string branch;
    public:
        Student(string n, int r, string b){
            name = n;
            roll = r;
            branch = b;
        }
};

class InternalExam : public Student{
    public:
        float marks[5]; // marks out of 30
        void GetMarks(){
            cout << "Enter marks in 5 subjects :\n";
            for (int i=0; i<5; i++){
                cin >> marks[i];
            }
        }
};

class MidSemesterExam : public Student{
    public:
        float marks[5]; // marks out of 20
        void GetMarks(){
            cout << "Enter marks in 5 subjects :\n";
            for (int i=0; i<5; i++){
                cin >> marks[i];
            }
        }
};

class EndSemesterExam : public Student{
    public:
        float marks[5]; // marks out of 50
        void GetMarks(){
            cout << "Enter marks in 5 subjects :\n";
            for (int i=0; i<5; i++){
                cin >> marks[i];
            }
        }
};

class Result : public InternalExam, public MidSemesterExam, public EndSemesterExam
{
    private:
        float total = 0;
    public:
        void Compute(){
            this->InternalExam::GetMarks();
            this->MidSemesterExam::GetMarks();
            this->EndSemesterExam::GetMarks();
        }
};

int main(){
    Student s[2] = {{"Harry Potter", 1, "CSE"},{"Ron Weasley", 2, "CSE"}};
    Result r;
}