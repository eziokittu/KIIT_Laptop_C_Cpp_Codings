// Code Studio Quiestion - Alica and Apple
// https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-61/7532028/problems/23649

#include <iostream>
#include <vector>

using namespace std;

int isTasty(int n, vector<int> &a) {
    // sort the array
    for (int i=0; i<a.size(); i++){
        for (int j=i+1; j<a.size(); j++){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

	return 0;
}

int main(){
    vector<int> a {1, 1, 2, 2};
    vector<int> k {1,2,3,4};
    cout << isTasty(4, a);
    cout << isTasty(4, k);
}