#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &edges, vector<int> &visited, stack<int> &s, int start){
  for (aut)
}

vector<int> getTopologicalOrder(vector<vector<int>> &edges, int n){
  vector<int> visited(n, 0);
  stack<int> s;
  for (int i=0; i<n; i++){
    if (visited[i] == 0){
      dfs(edges, visited, s, i);
    }
  }
}

int main() {

  // Getiing the number of nodes
  int n;
  cout << "Enter the no. of nodes: ";
  cin >> n;

  // Getting the edges of the graph
  vector<vector<int>> edges(n); 
  cout << "Enter the edges:\n";
  for (int i=0; i<n; i++) {
    cout << "Edge "<<i+1<< ": ";
    int a, b;
    cin>>a>>b;
    edges.push_back({a,b});
  }

  // Getting the topological order
  vector<int> order = getTopologicalOrder(edges, n);
}