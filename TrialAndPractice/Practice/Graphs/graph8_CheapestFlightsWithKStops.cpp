#include <iostream>
#include <vector>
// #include <priority_queue>
#include <queue>

// There are n cities and m edges connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from the city fromi to city toi with cost pricei.

// Dijkstra's Algorithm

using namespace std;

int CheapestFlight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {

}

int main() {
  vector<vector<int>> flights1 = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
  cout << CheapestFlight(4, flights1, 0, 3, 1);
}