#include <iostream>
#include <vector>
using namespace std;

string Longest_Common_Prefix(vector <string> &arr){
    string common = arr[arr.size()-1];

    return common;
}

int main(){
    vector<string> str = {"aaa1", "aaa2", "aaaaaaa", "aaa3"};
    cout << Longest_Common_Prefix(str);
    return 0;
}