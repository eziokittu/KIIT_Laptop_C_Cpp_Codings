#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int n, vector<int> edges[], int start){
  queue<int> q;
  vector<int> visited (n+1, 0);
  q.push(start);
  visited[start] = 1;

  cout << "Traversing the graph using BFS: ";
  
  while (!q.empty()){
    int node = q.front();
    q.pop();
    cout << node << " ";

    for (int i : edges[node]) {
      if(visited[i] != 1){
        visited[i] = 1;
        q.push(i);
      }
    }
  }
  cout << endl;
}

void undirected_graphs() {
  int n, m;
  cout << "Enter no. of nodes: ";
  cin >> n;
  cout << "Enter no. of edges: ";
  cin >> m;

  vector<int> edges[n+1]; // array of vectors for storing the edges (adjacency list)

  cout << "Enter the "<< m <<" edges:\n";
  for (int i=0; i<m; i++){
    cout << "Enter edge "<<i+1<<": ";
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  bfs(n, edges, 1);
}

int main() {
  undirected_graphs();
}