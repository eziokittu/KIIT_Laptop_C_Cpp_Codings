// LeetCode Problem 605 - Can Place Flowers
// https://leetcode.com/problems/can-place-flowers/

#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& s, int n) {
    vector<int> nums;
    int c=0;
    for (int i=0; i<s.size(); i++){
        if (((i==0) && (s[i]==0)) || ((i==s.size()-1)&&(s[s.size()-1]==0))){
            c+=2;
            if (i==s.size()+1){
                nums.push_back(c);
                break;
            }
        }
        else if (s[i]==0){
            c++;
        }
        else {
            cout << "g";
            if (c>1){
                cout << "\ni="<<i;
            }
            c=0;
        }
    }
    c=0;
    cout << endl<<"size="<<nums.size();
    for (int i=0; i<nums.size(); i++){
        cout << nums[i]<<" ";
    }
    cout << endl;
    for (int i=0; i<nums.size(); i++){
        c+=(nums[i]-1)/2;
    }
    if (c>=n){
        return true;
    }
    return false;
}

int main(){
    // vector<int> s = {1,0,0,0,1,0,0};
    vector<int> s = {0,0,1,0,0,0,1,0,0};
    cout << canPlaceFlowers(s, 3);
}