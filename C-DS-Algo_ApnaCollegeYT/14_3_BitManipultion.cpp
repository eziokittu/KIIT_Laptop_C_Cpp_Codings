#include <iostream>
#include <vector>

using namespace std;

// function using bit manipulation to find out the the unique int in an integer array, repeateed 2 times
int unique2(vector<int> &nums)
{
    int sum=0;
    for (int i=0; i<nums.size(); i++){
        sum = sum ^ nums[i];
    }
    return sum;
}

bool getBit(int n, int pos){
    return ((n & (1<<pos))!=0);
}

int setBit(int n, int pos){
    return (n | (1<<pos));
}

// function using bit manipulation to find out the the unique int in an integer array, repeateed 3 times
int unique3(vector<int> &nums){
    int result=0;
    for (int i=0; i<64; i++){
        int sum=0;
        for (int j=0; j<nums.size(); j++){
            if (getBit(nums[j], i)){
                sum++;
            }
        }
        if (sum%3!=0){
            result = setBit(result, i);
        }
    }
    return result;
}

int main(){
    vector<int> nums2 = {1,2,4,3,4,1,3};
    vector<int> nums3 = {1,3,4,2,3,1,4,1,4,3,2,2,8};
    cout << unique2(nums2)<<endl;
    cout << unique3(nums3)<<endl;

    return 0;
}