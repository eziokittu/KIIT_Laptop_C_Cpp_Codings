// LeetCode Problem 227 - Basic Calculator 2
// https://leetcode.com/problems/basic-calculator-ii/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
float getIntFromString(string s){
        float num = 0;
        for (int i=0; i<s.size(); i++){
            num = num*10 + s[i]-'0';
            // cout << "num = "<<num<<endl;
        }
        return num;
    }

    void tokenization(vector<float> &nums, vector<char>& ops, string s){
        string temp = "";
        for (int i=0; i<s.size(); i++){
            if (s[i]>='0' && s[i]<='9'){
                temp += s[i];
            }
            else if (s[i]=='-' || s[i]=='+' || s[i]=='*' || s[i]=='/'){
                ops.push_back(s[i]);
                if (temp!=""){
                    nums.push_back(getIntFromString(temp));
                    temp = "";
                }
            }
            else if (temp!=""){
                nums.push_back(getIntFromString(temp));
                temp = "";
            }
        }
        if (temp!=""){
            nums.push_back(getIntFromString(temp));
            temp = "";
        }
    }
    int calculate(string s) { 
        vector<float> nums;
        vector<char> ops;
        tokenization(nums, ops, s);

        // for (auto i : nums){
        //     cout << i << " ";
        // }cout<<endl;
        // for (auto i : ops){
        //     cout << i << " ";
        // }cout<<endl;

        long long ans;
        for(int i=0; i<ops.size(); ){
            if (ops[i]=='/'){
                if (nums[i+1]!=0)
                    nums[i] = nums[i]/nums[i+1];
                else
                    nums[i] = 0;
                nums.erase(nums.begin()+i+1);
                ops.erase(ops.begin()+i);
            }
            else 
                i++;
        }

        for (auto i : nums){
            cout << i << " ";
        }cout<<endl;
        for (auto i : ops){
            cout << i << " ";
        }cout<<endl;

        for(int i=0; i<ops.size(); ){
            if (ops[i]=='*'){
                nums[i] = nums[i]*nums[i+1];
                nums.erase(nums.begin()+i+1);
                ops.erase(ops.begin()+i);
            }
            else 
                i++;
        }

        for (auto i : nums){
            cout << i << " ";
        }cout<<endl;
        for (auto i : ops){
            cout << i << " ";
        }cout<<endl;

        for (float &i : nums){
            i = (int)i;
        }

        for(int i=0; i<ops.size(); ){
            if (ops[i]=='-'){
                nums[i] = nums[i]-nums[i+1];
                nums.erase(nums.begin()+i+1);
                ops.erase(ops.begin()+i);
            }
            else 
                i++;
        }
        for(int i=0; i<ops.size(); ){
            if (ops[i]=='+'){
                nums[i] = nums[i]+nums[i+1];
                nums.erase(nums.begin()+i+1);
                ops.erase(ops.begin()+i);
            }
            else 
                i++;
        }
        return nums[0];
    }
int main()
{
    // std::cout<<calculate("3 + 5 / 2 ");
    // std::cout<<calculate("2147483647");
    std::cout<<calculate("1+2*5/3+6/4*2");
    // std::cout<<calculate("4568+1276*3/2-27*4*9*2+4956/6");

    return 0;
}