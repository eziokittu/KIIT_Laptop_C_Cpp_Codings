#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    // using transform to make the string upper case
    string s1 = "sdfiuergherigherguner";
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    cout <<s1<<endl;

    // using transform to make the string lower case
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    cout <<s1<<endl;

    // using sort to arrange the string in numeric values
    string s = "3423789569234759342";
    sort (s.begin(), s.end(), greater<int>());
    cout << s;
}