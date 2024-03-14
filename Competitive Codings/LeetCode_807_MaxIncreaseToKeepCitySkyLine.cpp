// LeetCode Problem 807 - Max Increase to keep city Skyline
// https://leetcode.com/problems/max-increase-to-keep-city-skyline/

#include <iostream>
#include <vector>

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    vector<int> rows, cols;

    for (int i=0; i<grid.size(); i++){
        int rowMax = 0;
        for (int j=0; j<grid[0].size(); j++){
            if (grid[i][j]>rowMax){
                rowMax = grid[i][j];
            }
        }
        rows.push_back(rowMax);
    }

    for (int i=0; i<grid[0].size(); i++){
        int colMax = 0;
        for (int j=0; j<grid.size(); j++){
            if (grid[j][i]>colMax){
                colMax = grid[j][i];
            }
        }
        cols.push_back(colMax);
    }

    cout <<"\nRows:";
    for (auto i : rows) cout << " "<<i;
    cout <<"\nCols:";
    for (auto i : cols) cout << " "<<i;

    int sum = 0;
    for (int i=0; i<grid.size(); i++){
        for (int j=0; j<grid[0].size(); j++){
            sum += (min(rows[i], cols[j]) - grid[i][j]);
        }
    }

    return sum;
}
int main () {
    vector<vector<int>> grid = {
        {3,0,8,4},
        {2,4,5,7},
        {9,2,6,3},
        {0,3,1,0}
    };
    cout << maxIncreaseKeepingSkyline(grid) << endl;
}