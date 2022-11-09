// OOPs LAB Assignment - 7
// Q5) Rewrite the assignment vii. From inheritance inluding the
// parameterized constructors in all the classes. 

// NOT COMPLETED

#include <iostream>
using namespace std;

class Account {
    public:
        string number;
        string name;
        float balance;
        Account(){
            cout << "---Account Details---\nEnter account number : "; cin>>number;
            cout <<"Enter account name : "; cin >> name;
            balance = 0;
        }
        void DepositMoney(float f){
            balance+=f;
            cout<< "\nRs "<<f<<" has been deposited to the account";
        }
        void DisplayBalance(){
            cout << "\nCurrent Account Balace is: "<<balance;
        }
};

class Savings: public Account{
    private:
        float min = 1000; // minimum account balance is set to Rs 1000 [hardcoded]
    public:
        Savings(){
            cout <<"\nSavings Account Created! Rs1000 added as minimum balance.";
            balance = 1000;
        }
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

class Current: public Account{
    private:
        float over_due_amount;
    public:
        Current(){
            balance = 5000;
        }
        void Withdraw(){
            float f;
            while (1){
                cout <<"\nEnter amount : ";
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

    cout <<"\n\n\n----Savings Account----";
    acc1.DisplayBalance();
    acc1.DepositMoney(800);
    acc1.DisplayBalance();
    acc1.DepositMoney(2200);
    acc1.Withdraw();
    acc1.DisplayBalance();

    cout <<"\n\n\n----Current Account----";
    acc2.DisplayBalance();
    acc2.DepositMoney(100);
    acc2.DisplayBalance();
    acc2.DepositMoney(10000);
    acc2.Withdraw();
    acc2.DisplayBalance();

    return 0;
}