#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main () {
    vector<string> a = {"1.1", "4.2"};
    cout << stoi(a[0]) + stoi(a[1]) + 5;
}