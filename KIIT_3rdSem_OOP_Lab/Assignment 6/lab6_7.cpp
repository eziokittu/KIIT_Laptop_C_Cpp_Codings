// Q7) Create a class which stores account number, customer name and balance.
// Derive two classes from 'Account' class: 'Savings' and 'Current'. The
// savings class stores minimum balance. The 'Current' class stores the
// over-due amount. Include member functions in the appropriate class for
//      - deposit money
//      - withdraw [For savings account minimum balance should be checked
//                  For current account over-due amount should be calculated
//      ]
//      - display balance

#include <iostream>
using namespace std;

class Account {
    public:
        string number;
        string name;
        float balance=0;
        void DepositMoney(float f){
            balance+=f;
            cout<< "\nRs "<<f<<" has been deposited to the account";
        }
        void DisplayBalance(){
            cout << "\nCurrent Account Balace is: "<<balance;
        }
};

class Savings: public Account{
    public:
        float min = 1000; // minimum account balance is set to Rs 1000 [hardcoded]
        void Withdraw(){
            if (balance <= min){
                cout<<"\nMinimum balance needed for withdrawal";
            }
            else{
                int f;
                while (1){
                    cout <<"\nEnter amount : ";
                    cin >> f;
                    if (f<0 || balance-f>min){
                        cout << "Rs "<<f<<" amount has been withdrawn";
                        balance -= f;
                        return;
                    }
                    else{
                        cout << "\nToo much amount to withdraw!";
                    }
                }
            }
        }
};

// To calculate the interest due on a late payment, the amount of the debt
// should be multiplied by the number of days for which the payment is late,
// multiplied by daily late payment interest rate in operation on the date
// the payment became overdue.
class Current: public Account{
    public:
        void Withdraw(){
            
        }
};

int main(){
    Savings acc1;
    Current acc2;

    acc1.DisplayBalance();
    acc1.DepositMoney(800);
    acc1.DisplayBalance();
    acc1.DepositMoney(2200);
    acc1.Withdraw();
    acc1.DisplayBalance();
}