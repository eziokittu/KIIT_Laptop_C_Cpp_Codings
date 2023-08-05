// LeetCode Problem 227 - Basic Calculator 2
// https://leetcode.com/problems/basic-calculator-ii/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void extractNumbers(string s, vector<char>& ops, vector<int>& nums){
    int temp=-1;
    for (auto c : s){
        if (c-'0'>=0 && c-'0'<=9){
            if (temp==-1)temp=0;
            temp=(temp*10)-'0';
            temp+=c;
        }
        else{
            if (temp!=-1){
                nums.push_back(temp);
                temp=-1;
                if (c!=' ')
                ops.push_back(c);
            }
        }
    }
    if (temp!=-1){
        nums.push_back(temp);
    }
}
int calculate(string s) {
    string str ="";
    for (char c:s){
        if (c!=' ')
            str+=c;
    }
    if (str=="0") return 0;
    vector<char> ops;
    vector<int> nums;
    extractNumbers(str, ops, nums);
    // cout<<nums[0]<<endl;
    // for mul and div
    for (int i=0; i<ops.size();){
        int d;
        if (ops[i]=='/'){
            d = nums[i]/nums[i+1];
            nums.erase(nums.begin()+i);
            nums[i]=d;
            ops.erase(ops.begin()+i);
        }
        else if (ops[i]=='*'){
            d = nums[i]*nums[i+1];
            nums.erase(nums.begin()+i);
            nums[i]=d;
            ops.erase(ops.begin()+i);
        }
        else{
            i++;
        }
    }
    // for add and sub
    for (int i=0; i<ops.size();){
        int d;
        if (ops[i]=='+'){
            d = nums[i]+nums[i+1];
            nums.erase(nums.begin()+i);
            nums[i]=d;
            ops.erase(ops.begin()+i);
        }
        else if (ops[i]=='-'){
            d = nums[i]-nums[i+1];
            nums.erase(nums.begin()+i);
            nums[i]=d;
            ops.erase(ops.begin()+i);
        }
    }
    return nums[0];
}

int main()
{
    cout<<calculate("1+1+55")<<endl;
    cout<<calculate("0")<<endl;
    cout<<calculate("0+0")<<endl;
    cout<<calculate("2147483647")<<endl;
    cout<<calculate("0-2147483647")<<endl;
    cout<<calculate("3+5 / 2 ")<<endl;
    cout<<calculate("    3/2    ")<<endl;
    cout<<calculate("3+2*2")<<endl;

    return 0;
}