// LeetCode Problem 1971 - Find if path exists in graph
// 

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool dfs(int node, int destination, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
	if (node == destination) {
		return true;
	}
	visited.insert(node);
	for (int neighbor : graph[node]) {
		if (visited.find(neighbor) == visited.end()) {
			if (dfs(neighbor, destination, graph, visited)) {
				return true;
			}
		}
	}
	return false;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
	unordered_map<int, vector<int>> graph;
	for (const auto& edge : edges) {
		int u = edge[0];
		int v = edge[1];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	unordered_set<int> visited;
	return dfs(source, destination, graph, visited);
}


int main (){
	vector<vector<int>> edges = {{4,3},{1,4},{4,8},{1,7},{6,4},{4,2},{7,4},{4,0},{0,9},{5,4}};
	cout << validPath(10, edges, 5, 9);
}