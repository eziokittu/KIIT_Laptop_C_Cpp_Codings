#include <iostream>
#include <vector>
using namespace std;

string Longest_Common_Prefix(vector <string> &arr){
    string common;
    try
    {
        // initializing a string 'commom' with the last string element in the array
        common = arr[arr.size()-1];
        float flag = 0;
        // iterating the array fo string
        for (int i=0; i<arr.size()-1; i++){

            // iterating each letter of each string element
            for (int j=0; arr[i][j]!='\0'; j++){
                
                // comparing letter in 'common' to letter in that element
                if (common[j] != arr[i][j]) flag++;
            }
        }
    }
    catch(exception e)
    {
        return "";
    }
    return common;
}

int main(){
    vector<string> str = {"aaa1", "aaa2", "aaaaaaa", "aaa3"};
    cout << Longest_Common_Prefix(str);
    return 0;
}