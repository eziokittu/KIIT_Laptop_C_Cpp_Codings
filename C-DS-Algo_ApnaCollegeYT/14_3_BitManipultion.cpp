#include <iostream>
#include <vector>

using namespace std;

// Utility functions
bool getBit(int n, int pos){
    return ((n & (1<<pos)) !=0 );
}
int setBit(int n, int pos){
    return (n | (1<<pos));
}

// function using bit manipulation to find out the the unique int in an integer array, repeateed 2 times
void unique1(int nums[], int n)
{
    int sum=0;
    for (int i=0; i<n; i++){
        sum = sum ^ nums[i];
    }
    cout << "\n(1.) The unique number is "<<sum;
}

// WAP using bit manipulation to find 2 unique numbers in an array where all numbers except two are present twice
void unique2(int nums[], int n){
    int xorsum1 = 0;
    for (int i=0; i<n; i++){
        xorsum1 = xorsum1 ^ nums[i];
    }

    // finding the right most bit with 1
    int temp = xorsum1;
    int setbit = 0;
    int pos = 0;
    while (setbit != 1){
        setbit = temp & 1;
        pos++;
        temp = temp >> 1;
    }
    pos -= 1;

    int xorsum2 = 0;
    // now we have the position of the right most 1
    for (int i=0; i<n; i++) {
        if (getBit(nums[i], pos)){
            xorsum2 = xorsum2 ^ nums[i];
        }   
    }

    int a = xorsum2;
    int b = xorsum2 ^ xorsum1;
    cout << "\n(2.) The 2 unique numbers are "<<a<<" and "<<b;
}

// WAP using bit manipulation to find out the the unique integer number in an integer array, where all numbers except 1 are repeated thrice.
void unique3(int nums[], int n){
    int result=0;
    for (int i=0; i<64; i++){
        int sum=0;
        for (int j=0; j<n; j++){
            if (getBit(nums[j], i)){
                sum++;
            }
        }
        if (sum%3!=0){
            result = setBit(result, i);
        }
    }
    cout << "\n(3.) The unique number is "<<result;
}

int main(){
    int nums1[] = {1,2,4,3,4,1,3}; // 2 is unique
    unique1(nums1, 7);

    int nums2[] = {2,4,5,7,5,7,2,3,9,3}; // 4 and 9 are unique
    unique2(nums2, 10);

    int nums3[] = {1,3,4,2,3,2,4,1,4,3,8,2,1}; // 8 is unique
    unique3(nums3, 13);

    return 0;
}