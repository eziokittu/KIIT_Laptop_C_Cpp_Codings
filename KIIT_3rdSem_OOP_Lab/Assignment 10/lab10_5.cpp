// OOPs LAB Assignment - 10
// Q5) WAP to throw and handle 'array out of bound exception'

#include <iostream>
using namespace std;

int main() {
    int arr[6] = {10, 7, 8, 2, 1, 9};
    
    for (int i=0; i<100; i++){
        try{
            printf(" %d", arr[i]);
        }
        catch (exception e){
            cout << "[Array out of bounds exception] - " << e.what();
        }
    }
}