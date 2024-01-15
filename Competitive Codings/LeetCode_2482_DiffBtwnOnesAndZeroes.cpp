// LeetCode Problem 2482 - Difference Between Ones and Zeroes in Row and Coumns in grid
// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/?envType=daily-question&envId=2023-12-14

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    vector<int> rowSums, colSums;
    for (auto rows : grid){
        int count=0;
        for (int cols : rows){
            if (cols==1){
                count++;
            }
        }
        rowSums.push_back(count);
    }
    for (int i=0; i<grid[0].size(); i++){
        int count=0;
        for (int j=0; j<grid.size(); j++){
            if (grid[j][i] == 1){
                count++;
            }
        }
        colSums.push_back(count);
    }

    // cout << "\nPrinting rowSums: \n";
    // for (int i : rowSums) cout<<i<<"\n";
    // cout << "\nPrinting ColSums: \n";
    // for (int i : colSums) cout<<i<<" ";
    // cout<<endl;

    vector<vector<int>> ans;
    for (int i=0; i<rowSums.size(); i++){
        vector<int> temp;
        for (int j=0; j<colSums.size(); j++){
            temp.push_back(rowSums[i]+colSums[j]-(rowSums.size()-rowSums[i])-(colSums.size()-colSums[j]));
        }
        ans.push_back(temp);
    }
    return ans;
}

void print(vector<vector<int>> grid, string message){
    cout<<"\nPrinting the grid: ("+message+") \n";
    for (auto rows : grid){
        for (int cols : rows){
            cout<<cols<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    // vector<vector<int>> nums = {{0,1,1},{1,0,1},{0,0,1}};
    vector<vector<int>> nums = {{1,1,1},{1,0,1}};
    print(nums, "Before");
    nums = onesMinusZeros(nums);
    print(nums, "After");

    return 0;
}