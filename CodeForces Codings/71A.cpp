// 71A - Way too long words
// https://codeforces.com/problemset/problem/71/A

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> v;
    for (int i=0; i<=n; i++){
        string s;
        getline(cin, s);
        int count = s.size();
        if (count > 10){
            string str = "";
            str += s[0];
            str += to_string(count-2);
            str += s[s.size()-1];
            v.push_back(str);
        }
        else{
            v.push_back(s);
        }
    }
    for (string i: v){
        cout << i << endl;
    }

    return 0;
}