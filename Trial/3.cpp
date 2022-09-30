#include <iostream>
#include <limits>
using namespace std;

int reverse(int x) {  
    long rev=0,s=0;
    if(x<=INT32_MIN ||x>=INT32_MAX){
        return 0;
    }
    else{
        while(x!=0){
        rev=x%10;
        s=s*10+rev;
        x=x/10;
        } 
        if(s>=INT32_MIN && s<=INT32_MAX){ 
            return s; 
        }
        else{
            return 0;
        }
    }  
}

int main(){
    cout << reverse(INT32_MIN +16);
}