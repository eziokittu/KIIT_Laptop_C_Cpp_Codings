// LeetCode Problem 393 - UTF Validation
// 

#include <iostream>
#include <vector>
using namespace std;

// converts an ASCII number to its eqivalent binary in vector<int>
vector<int> getBinaryRepresentation(int n){
    vector<int> v;
    for (int i=128; i>=1; i=i/2){
        if (n>=i){
            v.push_back(1);
            n-=i;
        }
        else {
            v.push_back(0);
        }
    }
    return v;
}

// according to the question, gets the number of bytes 
// for the binary representation of UTF-8 Octet Sequence
int getNoOfBytes(vector<int> numInBin){
    if (numInBin[0]==0){
        return 1;
    }
    if (numInBin[0]==1 && numInBin[1]==0){
        return 0;
    }
    if (numInBin[1]==1 && numInBin[2]==0){
        return 2;
    }
    if (numInBin[2]==1 && numInBin[3]==0){
        return 3;
    }
    if (numInBin[3]==1 && numInBin[4]==0){
        return 4;
    }
    else {
    // if (numInBin[4]==1){
        return 5; // special case
    }
}

// returns the arrangement of number of bytes for all the numbers
vector<int> getArrangement(vector<vector<int>> n){
    vector<int> v;
    for (auto i : n){
        v.push_back(getNoOfBytes(i));
    }
    return v;
}

// checking if the sequence of arrangements is correct or not
// possible are combination of the following -
// 1
// 2 0
// 3 0 0
// 4 0 0 0
bool isArrangementCorrect(vector<int> a){
    if (a[0]==0) return false;
    double previous = 1;
    for (int i=0; i<a.size(); i++){
        // special case
        if (a[i]==5){
            return false;
        }

        cout << "\nChecking Arrangement Values: Previous="<<previous;
        cout << ", i="<<i<<", a[i]="<<a[i];

        // for 1 byte
        if (previous==1){
            previous = a[i];
        }
        else {
            // ending states 
            if (previous==2.1 || previous==3.2 || previous==4.3){
                    // cout << " DUBUG 1";
                if (a[i]==0){
                    return false;
                }
                else{
                    previous = a[i];
                }
            }
            // starting with 0
            else if (previous==0){
                    // cout << " DUBUG 2";
                return false;
            }
            // for 2 byte
            else if (previous <3){
                    // cout << " DUBUG 3";
                if (a[i]==0){
                    previous = 2.1;
                }
                else{
                    return false;
                }
            }
            // for 3 byte
            else if (previous <4){
                    // cout << " DUBUG 4";
                if (previous==3 && a[i]==0){
                    previous = 3.1;
                }
                else if (previous==3.1 && a[i]==0){
                    previous = 3.2;
                }
                else{
                    return false;
                }
            }
            // for 4 byte
            else if (previous <5){
                    // cout << " DUBUG 5";
                if (previous==4 && a[i]==0){
                    previous = 4.1;
                }
                else if (previous==4.1 && a[i]==0){
                    previous = 4.2;
                }
                else if (previous==4.2 && a[i]==0){
                    previous = 4.3;
                }
                else{
                    return false;
                }
            }
        }
    }
    // cout << "\n---Ending Checking Arrangement Values: Previous="<<previous;
    if (previous <= 1 || previous==2.1 || previous==3.2 || previous==4.3){
        return true;
    }
    return false;
}

bool MYCODE_validUtf8(vector<int>& data) {
    // array of binary representations
    vector<vector<int>> allNumsInBin;
    for (int num : data){
        allNumsInBin.push_back(getBinaryRepresentation(num));
    }
    vector<int> arrangement = getArrangement(allNumsInBin);

    cout <<"Arrangement - ";
    for (int i:arrangement){
        cout << i << " ";
    }

    return isArrangementCorrect(arrangement);
}

bool BESTCODE_validUtf8(vector<int>& data) {
    // data[i] is 8 bits acc to constraints

    int y = 0;
    for(int n : data){
        if(y == 0){
            if((n >> 7) == 0b0){
                y = 0;
            }else if((n >> 5) == 0b110){
                y = 1;
            }else if((n >> 4) == 0b1110){
                y = 2;
            }else if((n >> 3) == 0b11110){
                y = 3;
            }else{
                return false;
            }
        }else{
            if((n >> 6) == 0b10){
                y--;
            }else{
                return false;
            }
        }
    }
    return y == 0;
}

int main(){
    // vector<int> data = {197,130,1};
    // vector<int> data = {255};
    // vector<int> data = {230,136,145};
    vector<int> data = {145};
    cout << endl<< MYCODE_validUtf8(data);
    cout << endl<< BESTCODE_validUtf8(data);

    return 0;
}