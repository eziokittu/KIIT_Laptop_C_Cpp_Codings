// LeetCode Problem 56 - Merge n
// https://leetcode.com/problems/merge-n/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& n) {
    if (n.size()==1){
        return n;
    }
    
    // we sort the intervals based on starting interval
    for (int i=0; i<n.size()-1; i++){
        for (int j=i+1; j<n.size(); j++){
            if (n[i][0]>n[j][0]){
                vector<int> temp = n[i];
                n[i] = n[j];
                n[j] = temp;
            }
        }
    }
    // cout << "intervals are sorted!\n";

    // we minimize the intervals
    vector<vector<int>> ans;
    int start=n[0][0], end=n[0][1];
    for (int i=1; i<n.size(); i++){
        if (end<n[i][0]){
            ans.push_back({start,end});
            start = n[i][0];
            end = n[i][1];
        }
        else{
            if (end<n[i][1]){
                end=n[i][1];
            }
        }
        if (i==n.size()-1){
            ans.push_back({start,end});
            break;
        }
        // cout <<"for i="<<i<<", start="<<start<<", end="<<end<<endl;
    }
    // cout <<"After: intervals size="<<ans.size()<<endl;
    return ans;
}

int main(){
    vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> m = merge(v);
    for (auto i : m){
        cout<<i[0]<<", "<<i[1]<<endl;
    }

    return 0;
}