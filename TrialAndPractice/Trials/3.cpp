#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getTotalCombinations(int start, string s){
    int mul = 0;
    for (int i=s.size()-start-1; i>0; i--){
        mul*=i;
    }
    return mul;
}

void getString(string s, int start, vector<string>& v, int count, int k){
    if (count>k) return;
    if (start==s.size() and count==k){
        v.push_back(s);
        return;
    }
    int t = getTotalCombinations(start, s);
    count+=t;
    for (int i=start; i<s.size(); i++){
        swap(s[i], s[start]);
        getString(s, start+1, v, (i*count), k);
        swap(s[i], s[start]);
    }
}

string getPermutation(int n, int k) {
    string s;
    for(int i=1; i<=n; i++){
        s+=(char)('0'+i);
    }
    vector<string> v;
    getString(s, 0, v, 0, k);
    for (auto str: v){
        cout<<" "<<str;
    }
    return v[0];
}

int main(){
    string s = getPermutation(3,2);
    cout << "\n"<<s;

}