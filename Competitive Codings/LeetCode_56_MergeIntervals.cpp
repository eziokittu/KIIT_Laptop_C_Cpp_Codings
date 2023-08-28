// LeetCode Problem 56 - Merge n
// https://leetcode.com/problems/merge-n/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// sort all the intervals based on left side
// void sortIntervals(vector<vector<int>>& n) {
//     int s = n.size();
//     // classic bubble sorting
//     for (int i=0; i<s-1; i++){
//         for (int j=i+1; j<s; j++){
//             // swapping
//             if (n[j][0] < n[i][0]){
//                 vector<int> temp = n[j];
//                 n[j] = n[i];
//                 n[i] = temp;
//             }
//         }
//     }
// }

vector<vector<int>> merge(vector<vector<int>>& n) {
    // sortIntervals(n); // intervals are sorted

    // copied this following sorting ... from stack overflow
    sort(n.begin(), n.end(),
        [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    vector<vector<int>> v;
    v.push_back({n[0][0], n[0][1]});
    
    for (int i=1; i<n.size(); i++){
        int k=v.size()-1;
        // checking the left bounds
        if (n[i][0] <= v[k][1]){
            // checking the right bounds
            if (n[i][1] > v[k][1]){
                v[k][1] = n[i][1];
            }
        }
        else{
            v.push_back({n[i][0], n[i][1]});
        }
    }

    return v;
}

int main(){
    vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> m = merge(v);
    for (auto i : m){
        cout<<i[0]<<", "<<i[1]<<endl;
    }

    return 0;
}