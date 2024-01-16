#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPossible(int n, int f, int a, int b, vector<int> v){
    int start = 0;
    int cost = 0;
    for (auto i : v){
        int cost1 = (i-start)*a;
        int cost2 = b;
        // int temp = cost1>cost2 ? cost2 : cost1;
        int temp = cost1 + cost2;
        cost += temp;
        cout << "cost = "<<cost<<endl;
        if (cost >= f){
            return false;
        }
        start = i;
    }
    if (cost >= f)
        return false;
    return true;
}

int main() {
    int m;
    cin >> m;
    vector<string> ans;
    for (int i=0; i<m; i++){
        int n,f,a,b;
        cin>>n>>f>>a>>b;
        vector<int> v;
        for (int j=0; j<n; j++){
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        
        int temp = isPossible(n,f,a,b, v);
        if (temp==true)
            ans.push_back("YES");
        else
            ans.push_back("NO");
    }
    for (auto i : ans){
        cout << i << endl;
    }
}