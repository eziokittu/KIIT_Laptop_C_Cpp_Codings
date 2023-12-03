#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<vector<int>>& v){
    cout<<"Printing: [";
    for (int i=0; i<v.size(); i++){
        cout<<"[";
        for (int j=0; j<v[i].size(); j++){
            cout<<v[i][j];
            if (j!=v[i].size()-1){
                cout<<",";
            }
        }
        cout<<"]";
        if (i!=v.size()-1){
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

void sortVec2D(vector<vector<int>>& vec) {
    // defining the cost funtion
    // sorting the edges based on cost arranged in ascending order
    

    sort(vec.begin(), vec.end(),
        [](const vector<int>& a, const vector<int>& b) {return a[1] > b[1];}
    );
}

int main(){
    // vector<vector<int>> v = {{2,1,1},{2,3,1},{3,4,1}};
    vector<vector<int>> v = {{2,1,5},{2,3,2},{3,4,3}};
    print(v);
    sortVec2D(v);
    print(v);

    return 0;
}