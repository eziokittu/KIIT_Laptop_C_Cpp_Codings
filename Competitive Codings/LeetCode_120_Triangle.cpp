// LeetCode Problem 120 - Triangle finding the path minimum cost
// https://leetcode.com/problems/triangle/description/

#include <iostream>
#include <vector>

using namespace std;

int GetSum(int level, int index, int sum, vector<vector<int>> triangle, vector<vector<int>> &cost_table){
    if (level == triangle.size()){
        return sum;
    }

    int a,b;
    if (cost_table[level][index]!=999999999){
        a = GetSum(level+1, index, sum+triangle[level][index], triangle, cost_table);
        cost_table[level][index] = a;
    }
    else{
        a = cost_table[level][index];
    }
    if (cost_table[level][index+1]!=999999999){
        b = GetSum(level+1, index+1, sum+triangle[level][index+1], triangle, cost_table);
        cost_table[level][index+1] = b;
    }
    else{
        b = cost_table[level][index+1];
    }
    int m = (a>b ? b : a);
    if (cost_table[level][index]==999999999){
        cost_table[level][index] = m;
    }
    return (a>b ? b : a);
}

int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> cost_table;
    for (auto i : triangle){
        vector<int> temp(i.size(), 999999999);
        cost_table.push_back(temp);
    }
    int sum = triangle[0][0];
    return GetSum(1, 0, sum, triangle, cost_table);
}

int main () {
    vector<vector<int>> v = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << minimumTotal(v)<<endl;

    return 0;
}