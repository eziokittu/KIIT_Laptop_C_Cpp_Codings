// LeetCode Problem - 877 - StoneGame
// https://leetcode.com/problems/stone-game/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

bool stoneGame(vector<int>& piles) {
    int alice=0, bob=0;
    
    for (int i=0; i<piles.size(); i++){
        if (i%2==0){
            // Alice's turn
            alice += selectOptimalPile(piles);
        }
        else{
            // Bob's turn
            bob += selectOptimalPile(piles);
        }
    }

    if (alice >= bob){
        return true;
    }
    else return false;
}

int selectOptimalPile(vector<int>& piles){
    int n = piles.size();
    if (n<4){
        return (piles[0] > piles[n-1] ? piles[0] : piles[n-1]);
    }
    int a = piles[0];
    int b = piles[1];
    int c = piles[n-2];
    int d = piles[n-1];
    if (a+b < d){

    }
    else if (c+d < a){

    }
    else if (a+d ){

    }
}

int main(){
    vector<int> nums = {3,5,7,3};
    cout << stoneGame(nums);
}