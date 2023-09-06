// LeetCode Problem 224 - Basic Calculator 1
// https://leetcode.com/problems/basic-calculator/

#include <iostream>
#include <stack>
using namespace std;

// remove all spaces
string removeSpaces(string s){
    string str="";
    for (char c: s){
        if (c!=' '){
            str+=c;
        }
    }
    return str;
}

// calculate inside brackets
void getResult(stack<int> &numbers, stack<char> &symbols){
    while (numbers.size()>1 && symbols.size()>0) {
        int a = numbers.top();
        numbers.pop();
        int b = numbers.top();
        numbers.pop();
        char c = symbols.top();
        symbols.pop();

        if (c=='+'){
            numbers.push(b+a);
        }
        else if (c=='-'){
            numbers.push(b-a);
        }
    }
    if (symbols.top()=='('){
        symbols.pop();
    }
}

int calculate(string s) {
    s = removeSpaces(s);
    bool isNegative=false;
    int i=0;

    // to check if number starting is negative
    if (s[0]=='-'){
        i=1;
        isNegative = true;
    }

    // declaring the stacks and temporary number
    stack<int> numbers;
    stack<char> symbols;
    int num=0;

    // iterating the string
    for (; ; i++){ // s[i]!='\0'
        char c = s[i];

        // NUMBER
        if ( (c-'0')>=0 && (c-'0')<=9 ){
            num = (num*10) + (c-'0');
        }

        // SYMBOL
        else{
            // PUSH the previous number
            numbers.push(num);
            num=0; // refrest temporary number

            // PUSH
            if (c=='(' || c=='+' || c=='-'){
                symbols.push(c);
            }

            // POP
            else if (c==')'){
                getResult(numbers, symbols);
            }
        }

        // loop exit condition
        // exceptional - last letter
        if (s[i+1]=='\0'){
            // PUSH the previous number
            numbers.push(num);
            num=0; 

            // get the result
            getResult(numbers, symbols);

            break;
        }

        cout << numbers.top()<< " ";
    }
    cout <<endl;

    if (isNegative){
        return -(numbers.top());
    }
    return numbers.top();
}

int main(){
    // cout << calculate("1+1")<<endl;
    // cout << calculate("1-(     -2)")<<endl;
    cout << calculate("2333333+2-4")<<endl;
    // cout << calculate("- (3 + (4 + 5)          )")<<endl;
    // cout << calculate("-2  +1")<<endl;
    // cout << calculate("1-   5+1")<<endl;
}