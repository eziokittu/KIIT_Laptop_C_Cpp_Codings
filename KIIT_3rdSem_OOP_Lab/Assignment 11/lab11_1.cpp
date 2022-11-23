// OOPs LAB Assignment - 11 - File Handling
// Q1) WAP to display content of a file using character output function.

#include <iostream>
// A combination of ofstream and ifstream: creates, reads, and writes to files
#include <fstream>
using namespace std;

int main() {
    string filename = "lab11_1_text.txt";
    // open a file in read mode.
   fstream infile; 
   infile.open(filename); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 

   // write the data at the screen.
   cout << data << endl;
   
   // again read the data from the file and display it.
   infile >> data; 
   cout << data << endl; 

   // close the opened file.
   infile.close();
}