// LeetCode Problem 224 - Basic Calculator 1
// https://leetcode.com/problems/basic-calculator/

#include <iostream>
using namespace std;
int calculate(string str) {
    str='0'+str;
    string s="";
    int i=0;
    bool isNegative=false;
    while(true){
        char c = str[i]-'0';
        if (c>=0 && c<=9){
            break;
        }
        else {
            if (str[i]=='-'){
                isNegative=true;
            }
            i++;
        }
    }
    for (i=i; i<str.size(); i++){
        if (str[i]!=' ' && str[i]!=')' && str[i]!='('){
            // std::cout<<"for str[i]="<<str[i]<<", s[j]="<<s[s.size()-1]<<endl;
            if((str[i]=='-' && s[s.size()-1]=='-') ||
                (str[i]=='+' && s[s.size()-1]=='+')) {
                    // std::cout<<"------GG-------";
                s[s.size()-1]='+';
            }
            else if ((str[i]=='-' && s[s.size()-1]=='+') ||
                    (str[i]=='+' && s[s.size()-1]=='-')) {
                    // std::cout<<"------GG-------";
                s[s.size()-1]='-';
            }
            else 
                s+=str[i];
        }
    }
    // std::cout << "s= "<<s<<endl;
    int num1=0,num2=0;
    char op=' ';
    bool num2Active=false;
    for (char c:s){
        // std::cout <<"num1="<<num1<<", num2="<<num2<<", op="<<(char)op<<endl;
        if (c!='-' && c!='+'){
            if (num2Active){
                num2=num2*10+(c-'0');
            }
            else {
                num1=num1*10+(c-'0');
            }
        }
        else if ((op==' ') && (c=='-' || c=='+')){
            op=c;
            num2Active=true;
        }
        // else if ((op!=' ') && (c=='-' || c=='+')){
        else {
            if (op=='+'){
                num1=num1+num2;
            }
            else if (op=='-'){
                num1=num1-num2;
            }
            num2=0;
            op=c;
        }
    }
    if (op=='-')
        num1=num1-num2;
    else 
        num1=num1+num2;
    if (isNegative){
        return -num1;
    }
    return num1;
}

int main(){
    // cout << calculate("1+1")<<endl;
    // std::cout << calculate("1-(     -2)")<<endl;
    std::cout << calculate("- (3 + (4 + 5))")<<endl;
    std::cout << calculate("-2  +1")<<endl;
    // cout << calculate("1-   5+1")<<endl;
}