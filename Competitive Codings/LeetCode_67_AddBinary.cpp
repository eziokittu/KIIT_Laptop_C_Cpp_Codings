// LeetCode Problem - 67

#include <iostream>
using namespace std;

string addBinary(string a, string b) {
    int l1 = a.length();
    int l2 = b.length();
    string sum ="";

    bool hasCarry = false;
    for (int i=0; i<(l1>l2?l1:l2); i++){
        if (a[l1]=='1' && b[l2]=='1' && hasCarry){
            hasCarry = true;
            sum = "1" + sum;
        }
        else if (a[l1]=='1' && b[l2]=='1' && !hasCarry)
        {
            hasCarry = true;
            sum = "0" + sum;
        }
        else if (a[l1]=='0' && b[l2]=='0' && hasCarry)
        {
            hasCarry = false;
            sum = "1" + sum;
        }
        else if (a[l1]=='0' && b[l2]=='0' && hasCarry)
        {
            hasCarry = false;
            sum = "1" + sum;
        }
        else if (a[l1]=='1' && b[l2]=='0' && !hasCarry)
        {
            hasCarry = false;
            sum = "1" + sum;
        }
        else if (a[l1]=='1' && b[l2]=='0' && hasCarry)
        {
            hasCarry = true;
            sum = "0" + sum;
        }
        else if (a[l1]=='0' && b[l2]=='1' && hasCarry)
        {
            hasCarry = true;
            sum = "0" + sum;
        }
        else if (a[l1]=='0' && b[l2]=='1' && !hasCarry)
        {
            hasCarry = false;
            sum = "1" + sum;
        }
        l1--;
        l2--;
    }
}

int main(){

}