#include <iostream>
using namespace std;

class BA{
private:
    int account;
    double balance;

    void deposit(double amount){
        if(amount>0){
            balance += amount;
            cout << "Deposited : " << amount << endl;
            cout << "Balance : " << balance << endl;
        }
        else{
            cout << "Invalid deposit amount !!\n " << endl;
        }
    }

    void withdraw(double amount){
        if (amount > 0 && amount <= balance){
            balance -= amount;
            cout << "Withdrawn : " << amount << endl;
            cout << "Balance : " << balance << endl;
        }
        else if(amount > balance){
            cout << "Insufficient balance !!" << endl;
        }
        else{
            cout << "Invalid withdrawal amount !!\n" << endl;
        }
    }

public:
    BA(int acc, double bal){
        account = acc;
        balance = bal;
    }
    void details(){
        cout << "Account Number : " << account << endl;
        cout << "Balance : " << balance << endl;
    }
    void manageAccount(char operation, double amount){
        if (operation == 'd'){
            deposit(amount);
        }
        else if(operation == 'w'){
            withdraw(amount);
        }
        else{
            cout << "Invalid operation !!" << endl;
        }
    }
};

int main(){
    BA account1 (12345, 5000.0);
    account1.manageAccount('d', 3000.0);
    account1.manageAccount('w', 2000.0);
    account1.details();

    return 0;
}