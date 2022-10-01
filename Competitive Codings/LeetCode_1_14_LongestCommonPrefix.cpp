#include <iostream>
#include <vector>
using namespace std;

string Longest_Common_Prefix(vector<string> &str){
    // if the string array contains no elements
    if (str.size()==0) return "";

    // finding the string with the shortest length
    string small = str[0];
    for (int i=1; i<str.size(); i++){
        if (str[i].length()<small.length()){
            small = str[i];
        }
    }

    // iterating the shortest string 
    string common = "";
    for (int i=0; i<small.length(); i++){
        int flag=0;
        // comparing each character
        for (int j=0; j<str.size(); j++){
            if (small[i] != str[j][i]) flag++;
        }
        // if the character is same for all the string elements
        if (flag==0) common+=small[i];
        else break;
    }

    return common;
}

int main(){
    vector<string> s1 = {"ttHarry Potter", "tt24/7", "tt100.1", "ttMongoose king"};
    vector<string> s2 = {"flower", "flow", "flow", "flow"};
    vector<string> s3 = {"111","222","333","444","555","666","777","888","999"};
    vector<string> s4 = {};
    vector<string> s5 = {"dominoes", "dominator", "domination", "dominator", "domim"};
    cout << Longest_Common_Prefix(s1) << endl;
    cout << Longest_Common_Prefix(s2) << endl;
    cout << Longest_Common_Prefix(s3) << endl;
    cout << Longest_Common_Prefix(s4) << endl;
    cout << Longest_Common_Prefix(s5) << endl;
}