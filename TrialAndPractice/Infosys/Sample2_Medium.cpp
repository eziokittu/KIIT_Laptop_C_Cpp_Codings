// This question seems wrong - especially this line --
// "the value P[i] denotes that there is an edge between the node i and P[i]"
// contradics the sample cases ... I think
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> A;
vector<vector<int>> tree;
unordered_map<int, unordered_set<int>> subtree_values;

void dfs(int node, int parent)
{
  subtree_values[node].insert(A[node]);
  for (int child : tree[node])
  {
    if (child != parent)
    {
      dfs(child, node);
      for (int value : subtree_values[child])
      {
        subtree_values[node].insert(value);
      }
    }
  }
}

bool is_good_edge(int node, int parent)
{
  unordered_set<int> subtree1 = subtree_values[node];
  unordered_set<int> subtree2 = subtree_values[0];

  for (int value : subtree1)
  {
    subtree2.erase(value);
  }

  return (subtree1.size() + subtree2.size() == subtree_values[0].size());
}

int main()
{
  int N;
  cin >> N;
  A.resize(N);
  tree.resize(N);

  for (int i = 0; i < N; ++i)
  {
    cin >> A[i];
  }

  for (int i = 1; i < N; ++i)
  {
    int p;
    cin >> p;
    p--; // Converting to 0-based index
    tree[p].push_back(i);
    tree[i].push_back(p);
  }

  dfs(0, -1);

  int good_edges = 0;
  for (int i = 1; i < N; ++i)
  {
    if (is_good_edge(i, -1))
    {
      good_edges++;
    }
  }

  cout << good_edges << endl;
  return 0;
}

// Test case 1
// Input: 2 1 1 0 1
// Expected output: 1

// Test case 2
// Input: 4 1 2 3 4 0 1 2 3
// Expected output: 3

// Test case 3
// Input: 6 1 1 2 3 2 3 0 1 2 3 4 5
// Expected output: 0
