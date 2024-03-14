#include <iostream>
#include <vector>
#include <map>

using namespace std;

string checkPossible (string s, int a, int b){
    map<char, int> m;
    for (char i : s){
        m[i]++;
    }
    for (auto i: m){
        if (i.second < a){
            string temp = "";
            for (int j=0; j<a; j++){
                temp+=i.first;
            }
            return temp;
        }
    }
    if (m.size()==b)
        return "";
    else{
        char ch = 'a';
        for (auto i: m){
            if (i.first != ch){
                string temp = "";
                for (int j=0; j<a; j++){
                    temp+=ch;
                }
                return temp;
            }
            // cout << "-- DEBUG "<<i.first<< " "<<ch;
            ch++;
        }
        string temp = "";
        for (int j=0; j<a; j++){
            temp+=ch;
        }
        return temp;
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> ans;
    for (int i=0; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        string s;
        cin>>s;
        string q = checkPossible(s, a, b);
        if (q=="") {
            ans.push_back("YES");
        }
        else {
            ans.push_back("NO");
            ans.push_back(q);
        }
    }
    for (auto i : ans){
        cout << i << endl;
    }
}