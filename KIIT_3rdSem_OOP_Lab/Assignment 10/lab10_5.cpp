// OOPs LAB Assignment - 10
// Q5) WAP to throw and handle 'array out of bound exception'

#include <iostream>
using namespace std;

int main() {
    int arr[4] = {1,3,5,2};
    
    for (int i=-2; i<8; i++){
        try{
            cout << arr[i] << " ";
        }
        catch (exception e){
            cout << "[Array out of bounds EXCEPTION]";
            e.what();
            break;
        }
    }
    cout << "\nC++ compiler by default handles exception";
    cout << "\nBy showing garbage values.";
}