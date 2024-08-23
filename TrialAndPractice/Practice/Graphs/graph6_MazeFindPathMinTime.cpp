#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void visitCell(vector<string> &maze, vector<vector<int>> &visited, int r, int c, int a, int b){
  if (a>=0 && a<r && b>=0 && b<c){
    if (visited[a][b]==0 && maze[a][b]=='.'){
      maze[a][b]='-';
    }
  }
}

bool moveInPath(vector<string> &maze, queue<pair<int, int>> &q, vector<vector<int>> &visited, int r, int c){
  while (!q.empty()){
    int a = q.front().first;
    int b = q.front().second;

    // exit path found
    if (a==r-1 && b==c-1){
      return true;
    }

    q.pop();
    visited[a][b] = 1;

    visitCell(maze, visited, r, c, a-1, b);
    visitCell(maze, visited, r, c, a+1, b);
    visitCell(maze, visited, r, c, a, b-1);
    visitCell(maze, visited, r, c, a, b+1);
  }
  return false;
}

void printMaze(vector<string> maze, string message){
  cout << endl << message << endl;
  for (auto m : maze){
    cout << m << endl;
  }
}

int getMinTimeToSolveMaze(vector<string> maze){
  int r = maze.size();
  int c = maze[0].size();

  vector<vector<int>> visited(r, vector<int>(c, 0));
  maze[0][0] = '-'; // to keep track that this path has been visited
  queue<pair<int, int>> q;

  int time = -1;

  int i=0;
  while (true){
    string message = "Time - " + to_string(++i) + "";
    printMaze(maze, message);

    for (int i=0; i<r; i++){
      for (int j=0; j<c; j++){
        if (maze[i][j]=='-' && visited[i][j]==0){
          q.push({i,j});
        }
      }
    }
    
    // if no more new cells available
    if (q.empty()){
      return -1;
    }

    time++;
    if (moveInPath(maze, q, visited, r, c)){
      break;
    }
  }
  return time;
}

// Every maze has entry at top left corner, exit at bottom right corner.

int main() {
  vector<string> maze1 = {
    ".#",
    ".."
  };
  vector<string> maze2 = {
    ".#####",
    "..#...",
    "....#.",
    "####..",
    ".....#",
    "##..##",
    "###..."
  };
  
  vector<string> maze3 = {
    ".#####",
    "..#...",
    "....#.",
    "####..",
    "......",
    "##..#.",
    "###..."
  };

  int t = getMinTimeToSolveMaze(maze3);
  cout << "\nMin time to solve Maze 1: "<< t << endl;
}