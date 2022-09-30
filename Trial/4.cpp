#include <iostream>
using namespace std;

int main(){
    int a=10;
    for (int i=0; i<19; i++){
        cout << i;
        a+=i;
    }

    cout <<a;
    return 0;
}