#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void checkForLandAndMark(vector<vector<int>> &arr, vector<vector<int>> &visited, int r, int c, int a, int b, queue<pair<int, int>> &q){
  if (a>=0 && a<r && b>=0 && b<c){
    if (visited[a][b]==0 && arr[a][b]==1){
      visited[a][b] = 1;
      q.push({a,b});
    }
  }
}

void MarkIsland(vector<vector<int>> &arr, pair<int, int> start, vector<vector<int>> &visited, int r, int c){
  queue<pair<int, int>> q;
  q.push(start);
  while (!q.empty()){
    int a = q.front().first, b = q.front().second;
    visited[a][b] = 1;
    q.pop();

    checkForLandAndMark(arr, visited, r, c, a-1, b-1, q);
    checkForLandAndMark(arr, visited, r, c, a-1, b, q);
    checkForLandAndMark(arr, visited, r, c, a-1, b+1, q);
    checkForLandAndMark(arr, visited, r, c, a, b-1, q);
    checkForLandAndMark(arr, visited, r, c, a, b+1, q);
    checkForLandAndMark(arr, visited, r, c, a+1, b-1, q);
    checkForLandAndMark(arr, visited, r, c, a+1, b, q);
    checkForLandAndMark(arr, visited, r, c, a+1, b+1, q);
  }
}

int FindNumberOfIslands(vector<vector<int>> arr, int r, int c){
  vector<vector<int>> visited(r, vector<int>(c, 0));
  int islands = 0;
  for (int i=0; i<r; i++){
    for (int j=0; j<c; j++){
      if (visited[i][j]==0 && arr[i][j]==1){
        islands++;
        MarkIsland(arr, {i, j}, visited, r, c);
      }
    }
  }
  return islands;
}

int main(){
  vector<vector<int>> arr = {
    {0,1,1,0,0},
    {1,0,1,0,1},
    {0,0,0,0,1},
    {1,1,0,0,1}
  };

  cout << "The number of Islands: " << FindNumberOfIslands(arr, 4, 5);
}