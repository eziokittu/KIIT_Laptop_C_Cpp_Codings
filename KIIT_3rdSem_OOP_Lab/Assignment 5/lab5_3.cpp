// OOPs LAB Assignment 5
// Q3) Create a class which stores a string and it's length as data members.
// Include all the constructors. Include a member function to join two strings
// and display the concatenated strings 

#include <iostream>
using namespace std;

class Sentence{
    string str;
    int len;
    public:
        // Default Constructor
        Sentence (){
            str = "No sentence";
        }

        // Parameterised Contructors
        Sentence (string _s){
            str += _s;
            len = _s.length();
        }

        // Copy Constructors
        Sentence (const Sentence &s){
            str = s.str;
            len = s.len;
        }

        string JoinStrings(Sentence s2){
            return str+s2.str;
        }

        friend void Display(Sentence s);
};

void Display(Sentence s){
    cout <<"\nSentence is : "<<s.str;
}

int main(){
    Sentence s1;
    Sentence s2("Happy Diwali ");
    Sentence s3("and a happy new year!");
    Sentence s4(s3);

    Display(s1);
    Display(s2);
    Display(s3);
    Display(s4);

    cout <<"\nConcatenated Sentence is : "<< s2.JoinStrings(s4);
}