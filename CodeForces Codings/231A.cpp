// 231 A - Team
// https://codeforces.com/problemset/problem/231/A

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;
    for (short i=0; i<n; i++){
        int t = 0;
        for (short i=0; i<3; i++){
            short num;
            cin >> num;
            if (num==1){
                t++;
            }
        }
        if (t>=2){
            count++;
        }
    }

    cout << count;

    return 0;
}