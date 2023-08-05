// LeetCode Problem - 877 - StoneGame
// https://leetcode.com/problems/stone-game/

// #include <iostream>
// #include <stdio.h>
// #include <vector>

// using namespace std;

// bool stoneGame(vector<int>& piles) {
//     int alice=0, bob=0;
    
//     for (int i=0; i<piles.size(); i++){
//         if (i%2==0){
//             // Alice's turn
//             alice += selectOptimalPile(piles);
//         }
//         else{
//             // Bob's turn
//             bob += selectOptimalPile(piles);
//         }
//     }

//     if (alice >= bob){
//         return true;
//     }
//     else return false;
// }

// int selectOptimalPile(vector<int>& piles){
//     int n = piles.size();
//     if (n<4){
//         return (piles[0] > piles[n-1] ? piles[0] : piles[n-1]);
//     }
//     int a = piles[0];
//     int b = piles[1];
//     int c = piles[n-2];
//     int d = piles[n-1];
//     if (a+b < d){

//     }
//     else if (c+d < a){

//     }
//     else if (a+d ){

//     }
// }

// int main(){
//     vector<int> nums = {3,5,7,3};
//     cout << stoneGame(nums);
// }


int solve(vector<int>& markers, int i, int j, int sum, vector<vector<int>>& dp) {
    if(i>j)
        return 0;
    if(i==j)
        return markers[i];
    if(dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = max(sum - solve(markers, i+1, j, sum-markers[i], dp), sum - solve(markers, i, j-1, sum-piles[j], dp));
}
bool stoneGame(vector<int>& markers) {
    int n = markers.size();
    int sum = accumulate(markers.begin(), markers.end(), 0);
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int alexStones = solve(markers, 0, n-1, sum, dp);
    return alexStones > sum-alexStones;
}