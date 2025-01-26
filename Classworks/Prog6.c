#include <stdio.h>
#include <string.h>

struct BankAccount{
    char accHolder[100];
    float balance;
};

void deposit(struct BankAccount *account, float amount){
    if (amount > 0){
        account->balance += amount;
        printf("Amount deposited successfully.\nNew Balance : %.2f\n", account->balance);
    }
    else{
        printf("Invalid amount.\n");
    }
}

void withdraw(struct BankAccount *account, float amount){
    if (amount > 0 && amount <= account->balance){
        account->balance -= amount;
        printf("Amount withdrawn successfully.\nBalance : %.2f\n", account->balance);
    }
    else if (amount > account->balance){
        printf("Insufficient Balance !!!\n");
    }
    else{
        printf("Invalid Amount !\n");
    }
}

void display(struct BankAccount *account){
    printf("Account Holder Name : %s\n", account->accHolder);
    printf("Balance : %.2f\n", account->balance);
}

int main(){
    struct BankAccount account;
    printf("Enter account holder's name : ");
    fgets(account.accHolder, sizeof(account.accHolder), stdin);
    account.accHolder[strcspn(account.accHolder, "\n")] = '\0';
    account.balance = 0.0;
    int choice;
    float amount;

    do{
        printf("\nBank Account Menu\n");
        printf("1. Deposit\t");
        printf("2. Withdraw\t");
        printf("3. Display account details\t");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter amount to deposit : ");
                scanf("%f", &amount);
                deposit(&account, amount);
                break;

            case 2:
                printf("Enter amount to withdraw : ");
                scanf("%f", &amount);
                withdraw(&account, amount);
                break;

            case 3:
                display(&account);
            
            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice !!");
        }
    }
    while (choice != 4);

    return 0;
}