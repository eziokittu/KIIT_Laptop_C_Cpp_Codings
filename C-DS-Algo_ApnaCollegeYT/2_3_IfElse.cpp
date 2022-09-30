#include <iostream>
using namespace std;

int main(){

    // int savings;
    // cout << "Enter savings : ";
    // cin >> savings;
    // if (savings > 5000){
    //     cout << "\nGo out with girlfriend.";
    // }
    // else if (savings > 2000){
    //     if (savings>3000) cout << "\nGo out with Best Friend.";
    //     else cout << "\nGo out with school friends.";
    // }
    // else {
    //     cout << "\nGo out alone.";
    // }


    // Find the maximum number combining three given digits
    int num1, num2, num3;
    cout<<"Enter 1st number : ";
    cin>>num1;
    cout<<"Enter 2nd number : ";
    cin>>num2;
    cout<<"Enter 3rd number : ";
    cin>>num3;
    int max = 0;
    if (num1>num2 && num1>num3){
        max = num1*100;
        if (num2 > num3) max += (num2*10) + num3;
        else max += (num3*10) + num2;
    }
    else if (num2 > num3){
        max = num2*100;
        if (num1 > num3) max += (num1*10) + num3;
        else max += (num3*10) + num1;
    }
    else {
        max = num3*100;
        if (num1 > num2) max += (num1*10) + num2;
        else max += (num2*10) + num1;
    }
    cout << "\nMax number possible with " << num1 << ", " << num2 << ", "<< num3 << " = " << max << "\n\n";
}