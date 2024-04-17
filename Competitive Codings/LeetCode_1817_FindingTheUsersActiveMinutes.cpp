// LeetCode Problem 1817 - Finding the Users Active Minutes
// https://leetcode.com/problems/finding-the-users-active-minutes/description/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void print1(vector<pair<int, int>> v){
    cout << "\nPrinting Vector of pair:\n";
    for (auto i : v){
        cout << "["<<i.first<<","<<i.second<<"] ";
    }
    cout << endl;
}

void print2(unordered_map<int, int> v){
    cout << "\nPrinting Unordered Map of <int, int>:\n";
    for (auto i : v){
        cout << "["<<i.first<<","<<i.second<<"] ";
    }
    cout << endl;
}

void print3(vector<vector<int>> v){
    cout << "\nPrinting Vector of vector<int>:\n";
    for (auto i : v){
        cout <<"["<<i[0]<<" "<<i[1]<<"] ";
    }
    cout << endl;
}

void removeDuplicates(vector<vector<int>> &v) {
    int n = v.size();
    if (n <= 1) // If there are 0 or 1 elements, no duplicates to remove
        return;

    for (int i = 1; i < n; ) {
        if ((v[i][1] == v[i - 1][1]) && (v[i][0] == v[i - 1][0])) {
            v.erase(v.begin() + i); // Remove duplicates
            n--; // Decrement the size since we removed an element
        } else {
            i++; // Move to the next element
        }
    }
}

vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    sort(logs.begin(), logs.end(), [](vector<int> a, vector<int> b){
        if (a[1] == b[1]){
            return a[0] < b[0];
        }
        return a[1] < b[1];
    });

    print3(logs);
    removeDuplicates(logs);
    print3(logs);


    unordered_map<int, int> umap;
    for (int i=0; i<logs.size(); i++){
        umap[logs[i][0]]++;
    }
    
    print2(umap);
    
    vector<pair<int, int>> v;
    for (auto i : umap){
        v.push_back({i.first, i.second});
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });
    
    print1(v);
    
    vector<int> ans(k, 0);
    for (auto i=0; i<v.size(); i++){
        ans[v[i].second-1]++;
    }
    return ans;
}

int main()
{
    // vector<vector<int>> v = {{0,5},{1,2},{0,2},{0,5},{1,3}};
    vector<vector<int>> v = {{326924761,47805},{326924766,47806},{326924762,47806},{326924765,47803},{326924764,47802},{326924764,47804},{326924765,47806},{326924762,47806},{326924764,47805}};
    // vector<vector<int>> v = {{1,1},{2,2},{2,3}};
    vector<int> ans = findingUsersActiveMinutes(v, 5);
    for (auto i : ans){
        cout << i << " ";
    }

    return 0;
}