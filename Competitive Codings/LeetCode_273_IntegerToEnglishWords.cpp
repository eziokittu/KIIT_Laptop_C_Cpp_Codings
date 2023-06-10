// LeetCode Problem 273 - Integer to English words
// https://leetcode.com/problems/integer-to-english-words/

#include <iostream>
#include <vector>

#define vs vector<string> 

using namespace std;

int getMSB(int n){
    if (n<10) return n;
    return getMSB(n/10);
}

int removeMSB(int n){
    int s = n;
    int c = 0;
    while (s>9){
        c++;
        s=s/10;
    }
    // cout <<" "<< c<<" "<<s<<endl;
    while(c>0){
        s = s*10;
        c--;
    }
    // cout <<n<<endl<<s<<endl;
    return (n-s);
}

int noOfDigits(int n){
    if (n<10) return 1;
    return 1+noOfDigits(n/10);
}

void numToStr_LessThanThousand(int &num, string &s, vs list1, vs list2, vs list3, vs list4){
    int digit=0;
    while (num>0){
        // cout << " -3- ";
        int d = noOfDigits(num);
        if (d==3){
            digit = getMSB(num);
            s+=list1[digit];
            s+=list4[0];
            num = removeMSB(num);
        }
        else if (d==2){
            if (num<20){
                s+=list2[num%10];
                return;
            }
            else{
                digit = getMSB(num);
                s+=list3[digit-2];
                num = removeMSB(num);
            }
        }
        else {
            s+=list1[num];
            return;
        }
    }
}

void numToStr_LessThanMillion(int &num, string &s, vs list1, vs list2, vs list3, vs list4){
    int digit=0;
    while (num>0){
        // cout << " -2- ";
        int d = noOfDigits(num);
        if (d==7){
            digit = getMSB(num);
            s+=list1[digit];
            s+=list4[2];
            num = removeMSB(num);
        }
        else if (d>3){
            int temp = num/1000;
            numToStr_LessThanThousand(temp, s, list1, list2, list3, list4);
            if (num/1000>0) {
                s+=list4[1];
            }
            if (num>99999){
                num = removeMSB(num);
                if (noOfDigits(num)==5){
                    num = removeMSB(num);
                    if (noOfDigits(num)==4){
                        num = removeMSB(num);
                    }
                }
                if (noOfDigits(num)==4){
                    num = removeMSB(num);
                }
                // cout << "-1-num="<<num<<"d=="<<d<<"--";
            }
            else if (num>9999){
                num = removeMSB(num);
                if (noOfDigits(num)==4){
                    num = removeMSB(num);
                }
                // cout << "-2-num="<<num<<"d=="<<d<<"--";
            }
            else if (num>999){
                num = removeMSB(num);
                // cout << "-3-num="<<num<<"--";
                // cout<<noOfDigits(num);
            }
        }
        else{
            numToStr_LessThanThousand(num, s, list1, list2, list3, list4);
            return;
        }
    }
}

string numberToWords(int num) {
    vs list1= {
        "Zero", "One", "Two", "Three",
        "Four", "Five", "Six", "Seven",
        "Eight", "Nine"
    };
    vs list2 = {
        "Ten", "Eleven", "Twelve", "Thirteen",
        "Fourteen", "Fifteen", "Sixteen", "Seventeen",
        "Eighteen", "Nineteen"
    };
    vs list3 = {
        "Twenty", "Thirty", "Forty", "Fifty",
        "Sixty", "Seventy", "Eighty", "Ninety"
    };
    vs list4 = {
        "Hundred", "Thousand",
        "Million", "Billion"
    };
    if (num==0){
        return "Zero";
    }

    string s = "";
    int digit=0;
    while (num>0){
        // cout << " -1- ";
        int d = noOfDigits(num);
        if (d==10){
            digit = getMSB(num);
            s+=list1[digit];
            s+=list4[3];
            num = removeMSB(num);
            // cout << " --num="<<num;
        }
        else if (d<10 && d>6){
            // cout << " -1- ";
            int temp = num/1000000;
            numToStr_LessThanThousand(temp, s, list1, list2, list3, list4);
            if (num/1000000>0) {
                s+=list4[2];
            }
            if (num>99999999){
                num = removeMSB(num);
                if (noOfDigits(num)==8){
                    num = removeMSB(num);
                    if (noOfDigits(num)==7){
                        num = removeMSB(num);
                    }
                }
                if (noOfDigits(num)==7){
                    num = removeMSB(num);
                }
            }
            else if (num>9999999){
                num = removeMSB(num);
                if (noOfDigits(num)==7){
                    num = removeMSB(num);
                }
            }
            else if (num>999999){
                num = removeMSB(num);
            }
        }
        else{
            numToStr_LessThanMillion(num, s, list1, list2, list3, list4);
            break;
        }
    }
    string str="";
    for (int i=0; i<s.size(); i++){
        int c = s[i]-'A';
        if (c>=0 && c<=26 && i!=0){
            str+=" ";
        }
        str+=s[i];
    }
    return str;
}

int main(){
    // cout << numberToWords(19) << "-";
    // cout << numberToWords(20) << "-";
    cout << numberToWords(98) << endl;
    cout << numberToWords(23) << endl;
    cout << numberToWords(794) << endl;
    cout << numberToWords(999) << endl;
    cout << numberToWords(450) << endl;
    cout << numberToWords(300) << endl;
    cout << numberToWords(305) << endl;
    cout << numberToWords(123) << endl;
    cout << numberToWords(12345) << endl;
    cout << numberToWords(1234567) << endl;
    cout << numberToWords(2147483640) << endl;
    cout << numberToWords(909999) << endl;
    cout << numberToWords(667778890) << endl;
    // cout << getMSB(2147483640);
    // cout << removeMSB(2147483640);
    return 0;
}