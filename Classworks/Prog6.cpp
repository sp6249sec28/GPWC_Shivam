#include <iostream>
using namespace std;

struct BankAccount{
    string accHolder;
    float balance;

    void insertHolder(string name){
        accHolder = name;
    }
    void insertAmount(float bal){
        balance = bal;
    }

    void deposit(float amount){
        if(amount>0){
            balance += amount;
            cout << "Deposited Amount : " << amount << "\nBalance : " << balance << endl;
        }
        else{
            cout << "Invalid Amount...\n" << endl;
        }
    }

    void withdraw(float amount){
        if (amount>0 && amount<=balance){
            balance -= amount;
            cout << "Amount Withdrawn Successfully." << amount << "\nBalance : " << balance << endl;
        }
        else{
            cout << "No money available..." << endl;
        }
    }

    void accDetails(){
        cout << "Account Holder : " << accHolder << endl;
        cout << "Balance : " << balance << endl;
    }
};

int main(){
    struct BankAccount acc1;
    acc1.insertHolder("Shivam Patnaik");
    acc1.insertAmount(5000);

    acc1.deposit(4000);
    acc1.withdraw(2000);

    acc1.accDetails();

    return 0;
}