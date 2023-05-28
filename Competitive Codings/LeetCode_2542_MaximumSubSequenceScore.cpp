// LeetCode Problem 2542 - Maximum Sub Sequence Score
// https://leetcode.com/problems/maximum-subsequence-score/

// INCOMPLETE

#include <iostream>
#include <vector>

using namespace std;

void getCombination(int start, int end, int n, vector<vector<int>>& s){
    if (n>1){
        cout << "mm";
        s.push_back({});
        s[0].push_back(start);
        cout << "mm";
        getCombination(++start, end, --n, s);
        
        return;
    }
    else{
        vector<int> temp = s[0];
        s[0].push_back(start);
        int k=1;
        for (int i=++start; i<end; i++){
            s.push_back(temp);
            s[k++].push_back(i);
        }
        return;
    }
}

long Calculate(vector<vector<int>> s, vector<int> nums1, vector<int> nums2){
    long max=0;
    for (int i=0; i<s.size(); i++){
        long result=0, min;
        for (int j=0; j<s[0].size(); j++){
            cout << nums1[s[i][j]] << " ";
            result += nums1[s[i][j]];
        }

        for (int j=0; j<s.size(); j++){
            if (min >= nums2[s[i][j]]){
                cout << nums2[s[i][j]] << " ";
                min = nums2[s[i][j]];
            }
        }

        result = result * min;
        if (max<result){
            max = result;
        }
        cout << "gg ";
    }

    return max;
}

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    int l = nums2.size();
    if (l==0 || k<=0){
        return 0;
    }
    int start=0, end=l, max=0, count=1;
    while (true){
        cout << "gg";
        vector<vector<int>> comb;
        getCombination(start, end, k, comb);

        // cout <<"\nCombination-"<<count++<< ": ";
        // for (auto i : comb){
        //     cout << i<<" ";
        // }
        long temp = Calculate(comb, nums1, nums2);
        if (max < temp){
            max = temp;
        }
        comb.clear();
        start+=1;
        if (start+k > end){
            cout << "mm";
            break;
        }
        cout << "gg";
    }
    cout << "\n";
    return max;
}

int main(){
    vector<int> nums1 = {1,3,3,2,1,1,1,1,1};
    vector<int> nums2 = {2,1,3,4,1,1,1,1,1};
    cout << maxScore(nums1, nums2, 3) << endl;

    return 0;
}