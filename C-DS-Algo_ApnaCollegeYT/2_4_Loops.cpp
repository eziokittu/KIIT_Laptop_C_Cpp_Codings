#include <iostream>
using namespace std;

int main(){

    // for loop
    for (int i=0; i<10; i++){
        cout << i+1 << " ";
    }

    // while loop
    int j = 100;
    while (j<102) {
        cout << j+1 << " ";
        j++;
    }
    // do while
    int k = 1000;
    do {
        cout << k+1 << " ";
        k++;
    }
    while (k<1002);
}