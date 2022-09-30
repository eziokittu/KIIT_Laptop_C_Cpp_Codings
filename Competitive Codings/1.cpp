#include <string>
#include <iostream>
using namespace std;

int main(){
    string s[4] = {"Harry Potter", "tt", "100.1", "Mongoose king"};
    for (int i=0; i<s->length(); i++){
        for (int j=0; s[i][j]!='\0'; j++){
            cout << s[i][j] << "-";
        }
        cout << "\n";
    }
}