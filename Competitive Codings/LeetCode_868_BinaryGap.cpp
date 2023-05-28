// LeetCode Problem 868 - Binary Gap
// https://leetcode.com/problems/binary-gap/

#include <iostream>
#include <vector>

using namespace std;

int binaryGap(int n) {
    int gapstart=0, max=0;
    bool started = false;
    // cout<<((n&16)==16)<<((n&8)==8)<<((n&4)==4)<<((n&2)==2)<<((n&1)==1)<<endl;
    for (int i=1; i<n; i*=2){
        // cout << "For i="<<i<<": gapstart="<<gapstart<< ", max="<<max<<", started="<<started<<endl;
        if ((n & i)==i && (started==false)){
            started = true;
        }
        else if (started){
            if ((n & i)==0){
                gapstart++;
            }
            else{
                gapstart++;
                if (max<gapstart){
                    max = gapstart;
                }
                gapstart=0;
            }
        }
    }
    return max;
}

int main(){
    cout << binaryGap(22) << endl;
    // cout << binaryGap(8) << endl;
    // cout << binaryGap(5) << endl;
    return 0;
}