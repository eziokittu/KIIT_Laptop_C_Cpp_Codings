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
        Account(string _num, string _name, int b){
            number = _num;
            name = _name;
            balance = b;
            cout <<"\nAccount name: "<<name<<", number: "<<number;
            cout <<"\nRs"<<b<<" added as balance.";
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
    public:
        float min = 1000; // minimum account balance is set to Rs 1000 [hardcoded]
        Savings(string _num, string _name, int b)
        :Account(_num, _name, (b>=1000 ? b : 1000))
        {
            cout <<"\nSavings Account Created!";
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
    public:
        float over_due_amount = 5000;
        Current(string _num, string _name, int b)
        : Account(_num, _name, b)
        {
            cout <<"\nCurrent Account Created!";
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
    Savings acc1 ("SBI1001-saving", "Leonardo da Vinci", 900);
    Current acc2 ("SBI1002-current", "Mark Zukerberg", 10000);

    cout <<"\n\n----Savings Account----";
    acc1.DisplayBalance();
    acc1.DepositMoney(800);
    acc1.DepositMoney(2200);
    acc1.DisplayBalance();
    acc1.Withdraw();
    acc1.DisplayBalance();

    cout <<"\n\n----Current Account----";
    acc2.DisplayBalance();
    acc2.DepositMoney(100);
    acc2.DepositMoney(10000);
    acc2.DisplayBalance();
    acc2.Withdraw();
    acc2.DisplayBalance();

    return 0;
}