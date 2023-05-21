// LeetCode problem - 1588 - Sum of odd length sub arrays
//

#include <iostream>
#include <vector>

using namespace std;

int sumOddLengthSubarrays(vector<int>& arr) {
    long sum=0;
    for (int i=0; i<arr.size(); i++){
        int length = 1;
        while (true){
            cout<<"i="<<i<<", length="<<length<<endl;
            for (int j=0; j<length; j++){
                sum+=arr[i+j];
            }
            length+=2;
            if (i+length>arr.size()){
                break;
            }
        }
    }
    return sum;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};

    cout << sumOddLengthSubarrays(arr);

    return 0;
}