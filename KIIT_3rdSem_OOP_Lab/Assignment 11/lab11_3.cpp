// OOPs LAB Assignment - 11 - File Handling
// Q3) WAP to write 10 strings into a file and display them from file.

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    const string filename = "lab11_text_3.txt";
    fstream myfile;
    myfile.open(filename, ios::out | ios::in);
    if (myfile.is_open()){
        string lines[10];
        for (int i=0; i<10; i++){
            cout << "Enter 10 lines :\n";
            getline(cin>>ws, lines[i]);
            myfile << lines[i];
        }

        myfile.close();
    }

    return 0;
}