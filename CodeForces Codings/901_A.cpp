#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxTime(long a, long b, long n, vector<long> nums){
    // 5, 3, 3, {1,1,7} --> 1,1,5
    // 7, 1, 5, {1,2,5,6,8}

    // sort(nums.begin(), nums.end());
    long sum = 0;
    for (int i=0; i<n; i++){
        if (nums[i]>a){
            nums[i]=a-1;
        }
        sum += nums[i];
    }

    return sum + b;
}

int main(){
    int m;
    cin>>m;
    vector<int> ans;
    for (int i=0; i<m; i++){
        long int a, b, n;
        cin >>a>>b>>n;
        vector<long> nums;
        for (int j=0; j<n; j++){
            int num;
            cin >> num;
            nums.push_back(num);
        }

        ans.push_back(b>0 ? getMaxTime(a, b, n, nums) : 0);
    }

    for (auto i: ans){
        cout <<i<<endl;
    }
}
