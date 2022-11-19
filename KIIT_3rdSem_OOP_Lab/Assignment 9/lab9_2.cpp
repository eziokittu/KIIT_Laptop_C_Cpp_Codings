// OOPs LAB Assignment 9
// Q2)  Create a class which stores account number, customer name and balance.
// Derive two classes from ‘Account’ class: ‘Savings’ and ‘Current’. The ‘Savings’
//class stores minimum balance. The ‘Current’ class stores the over-due amount.
// Include member functions in the appropriate class for
//      -deposit money 
//      -withdraw
//          [For saving account minimum balance should be checked.] 
//          [For current account overdue amount should be calculated.] 
//      -display balance Display data from each class using virtual function.

#include <iostream>
using namespace std;

class Account {
    public:
        string number;
        string name;
        float balance=0;
        void DepositMoney(){
            float f;
            cout << "\nEnter money to deposit: ";
            cin >> f;
            balance+=f;
            cout<< "\nRs "<<f<<" has been deposited to the account";
        }
        void DisplayBalance(){
            cout << "\nCurrent Account Balace is: "<<balance;
        }
        virtual void Withdraw(){
            cout << "Withdraw not possible with creation of account!";
        }
};

class Savings: public Account{
    private:
        float min = 1000; // minimum account balance is set to Rs 1000 [hardcoded]
    public:
        void Withdraw(){
            if (balance <= min){
                cout<<"\nMinimum balance needed for withdrawal";
            }
            else{
                int f;
                while (1){
                    cout <<"\nEnter withdraw amount : ";
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

class Current: public Account{
    private:
        float over_due_amount=5000;
    public:
        void Withdraw(){
            float f;
            while (1){
                cout <<"\nEnter withdraw amount : ";
                cin >> f;
                if (f>0 && balance-f>=0){
                    if (f>over_due_amount)
                        cout<<"\nThe maximum amount that can be withdrawn is "<<over_due_amount;
                    else {
                        cout << "Rs "<<f<<" amount has been withdrawn";
                        balance -= f;
                        return;
                    }
                }
                else{
                    cout << "\nToo much amount to withdraw! OR Incorrect amount";
                }
            }
        }
};

int main(){
    Savings acc1;
    Current acc2;

    Account *acc;

    acc = &acc1;
    cout <<"\n\n\n----Savings Account----";
    acc->DepositMoney();
    acc->DisplayBalance();
    acc->DepositMoney();
    acc->DisplayBalance();
    acc->Withdraw();
    acc->DisplayBalance();

    acc = &acc2;
    cout <<"\n\n\n----Current Account----";
    acc->DepositMoney();
    acc->DisplayBalance();
    acc->DepositMoney();
    acc->DisplayBalance();
    acc->Withdraw();
    acc->DisplayBalance();

    return 0;
}