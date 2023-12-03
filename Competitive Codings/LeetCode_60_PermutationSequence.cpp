// Leetcode 60 - Permutation Sequence
// https://leetcode.com/problems/permutation-sequence/description/

#include<iostream>
#include<vector>
using namespace std;

string getPermutation(int n, int k) {
    // getting the factorial table
    vector<int> fact = {0,1};
    for (int i=2; i<=n; i++){
        fact.push_back(i*fact[fact.size()-1]);
    }

    vector<int> nums;
    for (int i=1; i<=n; i++){
        nums.push_back(i);
    }
    int c = 0;
    int count = 0;
    string ans = "";
    for (int i=n-1; i>=1; i--){
        cout<<"\nDEBUG - 1";
        while (count < k){
            cout<<"\nDEBUG-2.1: "<<"fact[i]="<<fact[i]<<", count="<<count<< ", c="<<c;
            if (fact[i] + count < k){
                cout<<"\nDEBUG-2.2: "<<"fact[i]="<<fact[i]<<", count="<<count<< ", c="<<c;
                count += fact[i];
                c++;
                cout<<" --- count="<<count<<", k="<<k;
            }
            else{
                ans += (char)('0'+nums[c]);
                nums.erase(nums.begin()+c);
                c=0;
                cout<<"\nDEBUG-3: Break at i="<<i<<" nums["<<c<<"]="<<nums[c];
                break;
            }
        }
    }
    for (int i : nums){
        ans += (char)('0'+i);
    }
    return ans;
}

int main(){
    string s = getPermutation(2,2);
    cout << endl<<s;
    return 0;
}