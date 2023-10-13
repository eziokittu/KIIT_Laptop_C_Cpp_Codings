#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> getMinMaxSum(vector<int> nums){
    // 1 2 9
    // 6 7 8

    // 2 8 9
    // 1 6 7

    // 1 2 8 -->max swapped
    // 6 7 9


    // 6 7 8
    // 1 2 9

    
    // 1 6 7
    // 2 8 9

    long min = nums[0];
    long max = nums[0];
    long sum = nums[0];
    for(int i=1; i<nums.size(); i++){
        if (min > nums[i]){
            min = nums[i];
        }
        if (max < nums[i]){
            max = nums[i];
        }
        sum += nums[i];
    }
    return {min, max, sum};
}

long getMaxPoints(int a, int b, int k, vector<int> nums1, vector<int> nums2){
    vector<long> minMaxSum_a = getMinMaxSum(nums1);
    vector<long> minMaxSum_b = getMinMaxSum(nums2);

    // for (auto i: minMaxSum_a){
    //     cout <<i<<" ";
    // }
    // cout<<endl;
    // for (auto i: minMaxSum_b){
    //     cout <<i<<" ";
    // }cout<<endl;

    // even
    if (k%2==0) {
        return minMaxSum_a[2];
    }
    // odd
    else{
        if (minMaxSum_a[2] < minMaxSum_a[2] - minMaxSum_a[0] + minMaxSum_b[1]  )
            return minMaxSum_a[2] - minMaxSum_a[0] + minMaxSum_b[1];
        else 
            return minMaxSum_a[2];
    }
}

int main(){
    int m;
    cin>>m;
    vector<int> ans;
    for (int i=0; i<m; i++){
        int a,b,k;
        cin>>a>>b>>k;
        vector<int> nums1,nums2;
        for (int i=0; i<a; i++){
            int num;
            cin>>num;
            nums1.push_back(num);
        }
        for (int i=0; i<b; i++){
            int num;
            cin>>num;
            nums2.push_back(num);
        }

        ans.push_back(getMaxPoints(a, b, k, nums1, nums2));
    }

    for (auto i: ans){
        cout <<i<<endl;
    }
}
