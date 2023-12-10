#include <iostream>
#include <vector>

using namespace std;

// brute force method
void getAdjacencyMatrix(vector<vector<int>> &m, vector<vector<int>> &edges, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (auto edge: edges){
                int u = edge[0], v = edge[1];
                if (u==i && v==j){
                    m[i][j] = 1;
                }
            }
        }
    }
}

int main()
{
    // getting the number of vertices
    int count_vertices;
    cout << "Enter the number of vertices: ";
    cin >> count_vertices;
    
    // getting the number of edges
    int count_edges;
    cout << "Enter the number of edges: ";
    cin >> count_edges;
    
    cout << "\n--- NOTE: edges are numbered from 0 to "<<count_vertices-1<<"(included) ---\n\n";
    
    // getting the pairs of edges
    vector<vector<int>> edges;
    cout << "Enter the edges pairs (u and v):\n";
    for(int i=0; i<count_edges; i++){
        int u, v;
        cout << "For edge["<<i+1<<"]: ";
        cin >> u >> v;
        edges.push_back({u, v});
    }
    
    // declaring and defining the adjacency matrix 
    vector<vector<int>> adjacencyMatrix;
    vector<int> temp;
    for (int i=0; i<count_vertices; i++){
        temp.push_back(0); 
    }
    for (int i=0; i<count_vertices; i++){
        adjacencyMatrix.push_back(temp); 
    }

    // calling the function toi get the adjacency matrix
    getAdjacencyMatrix (adjacencyMatrix, edges, count_vertices);

    // printing
    cout <<"-   ";
    for (int i=0; i<count_vertices; i++){
        cout <<i<<" ";
    }
    cout<<endl<<"   ";
    for (int i=0; i<count_vertices; i++){
        cout <<"--";
    }
    cout<<endl<<0<<" | ";
    for (int i=0; i<count_vertices; i++){
        for (int j=0; j<count_vertices; j++){
            cout << adjacencyMatrix[i][j]<< " ";   
        }
        if (i!=count_vertices-1)
            cout << "\n"<<i+1<<" | ";
    }

    return 0;
}