#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void PrintImage(vector<vector<int>> image){
  int r = image.size();
  int c = image[0].size();
  cout << "Printing the Image:\n";
  for (int i=0; i<r; i++){
    for (int j=0; j<c; j++){
      cout << image[i][j] << " ";
    }
    cout << endl;
  }
}

void CheckPixelAndUpdate(vector<vector<int>> &image, vector<vector<int>> &visited, queue<pair<int, int>> &q, int sr, int sc, int r, int c, int oldValue, int newValue){
  if (sr>=0 && sr<r && sc>=0 && sc<c){
    if (image[sr][sc]==oldValue && visited[sr][sc]==0){
      q.push({sr, sc});
    }
  }
}

void FloodFill(vector<vector<int>> &image, int sr, int sc, int newValue){
  int r = image.size();
  int c = image[0].size();
  int oldValue = image[sr][sc];
  vector<vector<int>> visited (r, vector<int>(c, 0));
  queue<pair<int, int>> q;
  visited[sr][sc] = 1;

  q.push({sr, sc});
  while (!q.empty()){
    int a = q.front().first;
    int b = q.front().second;
    image[a][b] = newValue;
    visited[a][b] = 1;
    q.pop();

    CheckPixelAndUpdate(image, visited, q, a-1, b, r, c, oldValue, newValue);
    CheckPixelAndUpdate(image, visited, q, a+1, b, r, c, oldValue, newValue);
    CheckPixelAndUpdate(image, visited, q, a, b-1, r, c, oldValue, newValue);
    CheckPixelAndUpdate(image, visited, q, a, b+1, r, c, oldValue, newValue);
  }
}

int main () {
  vector<vector<int>> image = {
    {0,1,1,2,2,2,0},
    {1,0,1,2,1,1,1},
    {0,2,1,3,2,2,1},
    {1,2,1,3,3,2,1},
    {1,0,1,1,1,1,1},
    {2,2,2,3,3,1,3}
  };

  PrintImage(image);
  FloodFill(image, 0, 1, 5);
  PrintImage(image);
}