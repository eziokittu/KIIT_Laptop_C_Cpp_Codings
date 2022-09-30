#include <iostream>
using namespace std;

int main(){
    // Print all the prime numbers in a number range of a to b
    int a, b;
    cin >> a >> b;
    for (int i=a; i<=b; i++){
        int j;
        for (j=2; j<i; j++){
            if (i%j == 0) break;
        }
        if (j==i) cout << i << " ";
    }
}