// Coding ninjas - Code Studio - Question
// https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-61/7532028/problems/23448?leftPanelTab=1

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minimumMoves(vector<int> &a, vector<int> &k) {
    // int moves = 0;
    // bool noMoreMoves = false;
    // while (!noMoreMoves){
    //     int c = 0;
    //     for (int i=0; i<a.size(); i++){
    //         if (a[i] <= 0) {
    //             c++;
    //         }
    //     }
    //     if (c==a.size()){
    //         noMoreMoves = true;
    //         break;
    //     }
    //     else {
    //         moves += 1;
    //     }
    //     for (int i=0; i<a.size(); i++){
    //         a[i] = a[i]-k[i];
    //     }
    // }
    // return moves;

    int moves = 0;
    for (int i=0; i<a.size(); i++){
        int c = ceil(a[i]/(float)k[i]);
        if (moves < c){
            moves = c;
        }        
    }
    return moves;
}

int main(){
    vector<int> a {17 ,27 ,6 ,25 ,15 ,44 ,37 ,8 ,37 ,3 ,31 };
    vector<int> k {43 ,30 ,7 ,42 ,30, 22, 39 ,18 ,47 ,28 ,39  };

    cout << minimumMoves(a, k);
}