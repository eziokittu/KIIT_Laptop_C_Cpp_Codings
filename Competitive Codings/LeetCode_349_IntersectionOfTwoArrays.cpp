// LeetCode Problem 349 - Intersection of Two Arrays
// 

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> m;
    vector<int> v;
    for (int i : nums1){
        if (m[i]<1)
            m[i]++;
    }
    for (int i : nums2){
        if (m[i]==1)
            m[i]=2;
    }
    for (auto it: m){
        if (it.second==2){
            v.push_back(it.first);
        }
    }
    return v;
}

int main(){
    vector<int> a = {1,2,3,2,1,5,1,4,2};
    vector<int> b = {2,4,9,8,0};
    vector<int> c = intersection(a, b);
    for (auto i: c){
        cout << " "<< i;
    }

    return 0;
}