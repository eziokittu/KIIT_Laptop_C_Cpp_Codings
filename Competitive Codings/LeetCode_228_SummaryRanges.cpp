// LeetCode problem 228 - Summary Ranges
// https://leetcode.com/problems/summary-ranges/
#include <iostream>
#include <vector>
using namespace std;

string getRequiredString(int a, int b){
    if (a==b){
        return to_string(a);
    }
    string s="";
    s+=to_string(a);
    s+="->";
    s+=to_string(b);
    return s;
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> str;
    if (nums.size()==0){
        return str;
    }
    string s="";
    int oldStart=nums[0], newStart=nums[0],end;
    for (int i=1; i<nums.size(); i++){
        end=nums[i];
        long diff = (long)end-(long)newStart;
        if (diff<=1){
            if (newStart==-2147483648 && end!=2147483647){
                oldStart=end;
                newStart=end;
                str.push_back("-2147483648");
            }
            else
                newStart=end;
        }
        else if (diff>1 || i==nums.size()-1){
            if (oldStart==newStart){
                s=getRequiredString(oldStart, oldStart);
            }
            else{
                s=getRequiredString(oldStart, newStart);
            }
            oldStart=end;
            newStart=end;
            str.push_back(s);
            s="";
        }
    }
    if (oldStart==newStart){
        s=getRequiredString(oldStart, oldStart);
    }
    else{
        s=getRequiredString(oldStart, newStart);
    }
    oldStart=end;
    newStart=end;
    str.push_back(s);
    s="";
    return str;
}

int main(){
    // vector<int> nums = {0,2,3,4,7,8,9};
    vector<int> nums = {-2147483648,-2147483647,2147483647};
    // vector<int> nums = {-2147483648,-2147483647,2147483647};
    // vector<int> nums = {-2147483648,-2147483647, -2147483646, 2147483647};
    vector<string> s = summaryRanges(nums);
    for (auto i: s){
        cout << i <<", ";
    }
    cout << endl;
    // cout << getRequiredString(11,811);
    // cout << to_string(-2147483649);
    return 0;
}