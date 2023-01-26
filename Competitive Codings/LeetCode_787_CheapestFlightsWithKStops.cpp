// LeetCode Problem - 787 - Cheapest Flights With K stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <iostream>
#include <vector>

using namespace std;

int FindPath(vector<vector<int>>& flights, int src, int dst, int cost, int k){
    for (int i=0; i<flights.size(); i++){
        if (flights[i][0] == src){
            // if destination is reached
            if (flights[i][1] == dst){
                cost += flights[i][2];
                return cost;
            }
            // destination not reached
            else {
                if (k>0){
                    cost += flights[i][2];
                    k -= 1;
                    src = flights[i][1];
                    return FindPath(flights, src, dst, cost, k);
                }
            }
        }
    }
    return -1;
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    int cost=0;
    return FindPath(flights, src, dst, cost, k);
}

int main(){
    vector <vector<int>> flights {{3,4,4},{2,5,6},{4,7,10},{9,6,5},{7,4,4},{6,2,10},{6,8,6},{7,9,4},{1,5,4},{1,0,4},{9,7,3},{7,0,5},{6,5,8},{1,7,6},{4,0,9},{5,9,1},{8,7,3},{1,2,6},{4,1,5},{5,2,4},{1,9,1},{7,8,10},{0,4,2},{7,2,8}};
    int n=10, src = 6,dst = 0, k = 7;
    cout << findCheapestPrice(n, flights, src, dst, k);

    return 0;
}