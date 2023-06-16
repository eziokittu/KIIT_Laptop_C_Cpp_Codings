// LeetCode Problem - 42 - Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/
#include <iostream>
#include <vector>

using namespace std;

bool allUnnecessaryRidgesRemoved(vector<int> n, vector<int>& v){
    bool toReturn=true;
    for(int i=1; i<v.size()-1; ){
        int a=n[v[i-1]], b=n[v[i]], c=n[v[i+1]];
        // cout <<"a="<<a<<" b="<<b<<" c="<<c;
        if ((b<=a) && (b<=c)){
            // cout << "--Removed "<<b;
            v.erase(v.begin()+i);
            toReturn = false;
            break;
        }
        else{
            i++;
        }
    }
    return toReturn;
}

vector<int> findRidgeIndices(vector<int> n){
    vector<int> v;
    bool ridgeFound = false;
    int index=0;
    for (int i=1; i<n.size(); i++){
        if (n[index]>=n[i] && ridgeFound==false){
            v.push_back(index);
            ridgeFound=true;
        }
        else if (n[index]<n[i] && ridgeFound==true){
            ridgeFound=false;
        }
        index=i;
        if (i==n.size()-1){
            if (n[index]>n[index-1]){
                v.push_back(index);
                break;
            }
        }
    }
    while (true){
        bool isTrue = allUnnecessaryRidgesRemoved(n, v);
        if (isTrue==true){
            break;
        }
    }
    return v;
}

int trap(vector<int>& n) {
    if (n.size()<3)return 0;
    int left=n[0], right;
    vector<int> ridges = findRidgeIndices(n);
    for (auto i:ridges){
        cout << "n["<<i<<"]="<<n[i]<<" ";
    } cout<<endl;
    
    int sum=0;
    for (int i=1; i<ridges.size(); i++){
        int start = ridges[i-1];
        int end = ridges[i];
        int min = (n[start] < n[end] ? n[start] : n[end]);
        for (int j=start+1; j<end; j++){
            int diff = min-n[j];
            sum+= (diff>0 ? diff : 0);
        }
    }
    return sum;
}

int main()
{
    // vector<int> nums = {0,3,2,0,3,2,1,0,2,4,1,3,0}; // 13
    // vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1}; // 6
    // vector<int> nums = {5,5,1,7,1,1,5,2,7,6}; // 23
    vector<int> nums = {5,3,7,7}; // 23
    // vector<int> nums = {0,1,2,0,3,0,1,2,0,0,4,2,1,2,5,0,1,2,0,2}; 
    // vector<int> nums = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3}; // 83
    // vector<int> nums = {0,5,6,4,6,1,0,0,2,7}; // 23
    // vector<int> nums = {4,2,0,3,2,5}; // 9
    cout<<trap(nums);
    return 0;
}