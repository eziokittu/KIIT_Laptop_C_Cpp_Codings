#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void CheckCellAndMark(vector<vector<int>> &basket, int a, int b, int r, int c){
  if (a>=0 && a<r && b>=0 && b<c){
    if (basket[a][b]==1){
      basket[a][b]=2;
    }
  }
}

void RottenAdjacentOranges(vector<vector<int>> &basket, vector<vector<int>> &visited, queue<pair<int, int>> &q, int r, int c){
  while (!q.empty()){
    int a = q.front().first;
    int b = q.front().second;
    visited[a][b] = 1;
    q.pop();

    CheckCellAndMark(basket, a-1, b, r, c);
    CheckCellAndMark(basket, a+1, b, r, c);
    CheckCellAndMark(basket, a, b-1, r, c);
    CheckCellAndMark(basket, a, b+1, r, c);
  }
}

int GetTimeToRottenOranges(vector<vector<int>> &basket, int r, int c){
  vector<vector<int>> visited(r, vector<int>(c, 0));
  queue<pair<int, int>> q;
  int time = -1;
  while (true) {
    for (int i=0; i<r; i++){
      for (int j=0; j<c; j++){
        if (basket[i][j]==2 && visited[i][j]==0){
          q.push({i, j});
        }
      }
    }
    if (q.empty()){
      break;
    }
    else {
      time++;
      RottenAdjacentOranges(basket, visited, q, r, c);
    }
  }
  return time;
}

int main() {
  vector<vector<int>> basket = {
    {0,1,1,2},
    {1,0,1,1},
    {1,0,1,0},
    {1,1,1,1}
  };
  int r = basket.size(), c = basket[0].size();

  cout << "Time to rotten all fresh oranges in basket is: "<< GetTimeToRottenOranges(basket, r, c) << " unit time.";
}