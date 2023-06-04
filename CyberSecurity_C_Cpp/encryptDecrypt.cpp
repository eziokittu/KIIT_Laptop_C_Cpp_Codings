#include <iostream>

using namespace std;

int other_multiplicativeInverse(int a, int m){
    for (int i = 3; i < m; i+=2){
        if ((i*a)%m == 1){
            // cout << "multiplicative inverse of "<<a<<" MOD "<<m<<" = "<<i<<endl;
            return i;
        }
    }
}

string encryption_additive(string plainText, int key){
    string cipherText = "";
    for (int i=0; i<plainText.size(); i++){
        char c = (plainText[i]-'a'+key)%26+'a';
        cipherText += c;
    }
    return cipherText;
}   

string decryption_additive(string cipherText, int key){
    string plainText = "";
    for (int i=0; i<cipherText.size(); i++){
        char c = (cipherText[i]-'a'-key+26)%26+'a';
        plainText += c;
    }
    return plainText;
}

string encryption_multiplicative(string plainText, int key){
    string cipherText = "";
    for (int i=0; i<plainText.size(); i++){
        char c = ((plainText[i]-'a')*key)%26+'a';
        cipherText += c;
    }
    return cipherText;
}

string decryption_multiplicative(string cipherText, int key){
    int newKey = other_multiplicativeInverse(key, 26);
    string plainText = "";
    for (int i=0; i<cipherText.size(); i++){
        char c = ((cipherText[i]-'a')*newKey)%26+'a';
        plainText += c;
    }
    return plainText;
}

int main(){
    // for (int i=0; i<26; i++){
    //     cout<<(char)('a'+i)<<"  ";
    // }
    // cout<<"\n";
    // for (int i=0; i<26; i++){
    //     cout<<i;
    //     if (i<10){
    //         cout << "  ";
    //     }
    //     else {
    //         cout << " ";
    //     }
    // }
    // cout<<"\n";
    string test = "thisisanexercise";
    string res1_additive = encryption_additive(test, 20); // nbcmcmuhyrylwcmy
    string res2_multiplicative = encryption_multiplicative(test, 15); // zbqkqkanihiveqki
    cout << res1_additive << endl << res2_multiplicative<<endl;
    cout << ((decryption_additive(res1_additive, 20) == test) ? "--true--" : "--false--") <<endl;
    cout << ((decryption_multiplicative(res2_multiplicative, 15) == test) ? "--true--" : "--false--") <<endl;
    cout<<"\n";
    return 0;
}