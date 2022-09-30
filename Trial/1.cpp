#include<iostream>
#include<vector>
using namespace std;

string smallest(vector <string> arr){
    string small=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]<small){
            small=arr[i];
        }
    }
    return small;

}

void alt(vector <string> &arr){
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
    alt(str);
    return 0;
}