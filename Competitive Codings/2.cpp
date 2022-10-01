#include<iostream>
#include<vector>
using namespace std;

// string smallest(vector <string> arr){
//     string small=arr[0];
//     for(int i=1; i<arr.size(); i++){
//         if(arr[i]<small){
//             cout << "\narr["<<i<<"] = "<<arr[i];
//             cout << ", small = "<<small;
//             small=arr[i];
//         }
//     }
//     return small;

// }

void Longest_Common_Prefix(vector<string> &arr){
    bool isflag=false;
    string st_cmn="";
    for(int i=0;i<smallest(arr).length() && i<arr.size();i++){
        char ch=smallest(arr).at(i);
        for(int k=0;k<arr.size();k++){
            char m=arr[k].at(i);
            if (m==ch)
            {
                /* code */
                isflag=true;
                continue;
            }
            else{
                isflag=false;
                break;
            }
        }
        if (isflag)
        {
        cout<<ch<<endl;
          st_cmn=st_cmn+ch;
        }
        else{
            break;
        }
        
    }
}

int main(){
    vector <string> str={"kkkielo","kki","kkktilla"};
    //cout << "\nsmallest string is of lenght - " << smallest(str).length() << "\n";
    Longest_Common_Prefix(str);
    return 0;
}