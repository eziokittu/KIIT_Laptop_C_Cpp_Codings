#include <iostream>
#include <vector>
#include <queue>

// Dijkstra's Algorithm

using namespace std;

vector<int> DijksrasAlgo(int v, vector<vector<int>> adj[], int src)  {

  // Initialize a priority queue with min heap
  priority_queue<
    pair<int, int>, // first denotes the distance, second denotes the node
    vector<pair<int, int>>, 
    greater<pair<int, int>>
  > pq;

  // Initialize a distance vector
  vector<int> dist (v, 1e9); // definind with a very large value

  // Source distance is 0
  dist[src] = 0;

  // Pushing the source into the priority queue
  pq.push({0, src});

  // Iteratinng until the priority queue is empty
  while (!pq.empty()){
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (auto it : adj[node]){
      int adjNode = it[0];
      int edgeWeight = it[1];

      if (dis + edgeWeight < dist[adjNode]){
        dist[adjNode] = dis + edgeWeight;
        pq.push({dist[adjNode], adjNode});
      }
    }
  }
  return dist;
}


// Utility function to print the adjacency list
void Print(vector<vector<int>> adj[], int n){
  cout << "Printing the adjacency list: \n";
  for (int i=0; i<n; i++){
    cout << i << " -- ";
    for (auto j : adj[i]){
      cout << "node="<<j[0]<<" dist="<<j[1]<<" --- ";
    }
    cout << endl;
  }
}


int main() {
  int n = 4;
  vector<vector<int>> adj[n] = {
    {{1,7}, {2, 2}, {3,6}},
    {{2,1}},
    {{3,2}},
    {{1,1}, {2,2}},
  };
  vector<int> dist =  DijksrasAlgo(4, adj, 0);

  Print(adj, n);

  cout << "From the source 0 the minimum distances are : \n";
  for (int i=0; i<n; i++){
    cout << "0 --> "<<i<< " == "<<dist[i]<<endl;
  }
}