#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<int> edges[], vector<int> &visited, int start){
  if (visited[start] == 1){
    return;
  }
  visited[start] = 1;
  for (int i : edges[start]){
    dfs(edges, visited, i);
  }
}

int FindNumberOfProvinces(int n, vector<int> edges[]){
  vector<int> visited(n+1, 0);
  int provinces = 0;
  for (int i=1; i<=n; i++){
    if (visited[i]==0){
      dfs(edges, visited, i);
      provinces++;
    }
  }
  return provinces;
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

  cout << "The number of provinces in theis graph is: "<< FindNumberOfProvinces(n, edges);
}

int main() {
  undirected_graphs();
}