// 158 A - Next Round
// https://codeforces.com/problemset/problem/158/A

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    
    int count = 0;
    int last = 0;
    bool lastReached = false;
    for (int i=0; i<n; i++){
        int num;
        cin>> num;
        if (count<k && num>0){
            count++;
        }
        else if (count>=k && last == num && lastReached==false && num>0){
            count++;
        }
        else{
            lastReached = true;
        }
        last = num;
    }

    cout << count;

    return 0;
}