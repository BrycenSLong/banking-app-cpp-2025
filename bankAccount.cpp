#include "bankAccount.h"
#include <iostream>
#include <string>

// Default bank account constructor

BankAccount::BankAccount(int accNum, double initialBalance) {
    ownerFirstName = "";
    ownerMiddleAnitial = '\0';
    ownerLastName = "";
    balance = 0.0;
    accountNumber = 0;

}

void BankAccount::deposit(int accNum, double initialBalance) {
    if (accNum != accountNumber) {
        std::cerr << "Error: Account number does not match." << std::endl;
        return;
    } else if (accNum == accountNumber){
        if(initialBalance < 0) {
            std::cerr << "Error: Deposit amount must be positive." << std::endl;
            return;
        } else {
            balance += initialBalance;
            std::cout << "Deposited: $" << initialBalance << std::endl;
            std::cout << "New Balance: $" << balance << std::endl;
        }
        
    }
}

void BankAccount::withdraw(double amount) {
    if(amount < 0) {
        std::cerr << "Error: Withdrawl amount must be positive." << std::endl;
        return;
    } else if(amount > balance){
            std::cerr << "Error: Insufficient funds." << std::endl;
            return;
    } else {
        balance -= amount;
        std::cout << "Withdrew: $" << amount << std::endl;
        std::cout << "New Balance: $" << balance << std::endl;
    }
}

double BankAccount::getBalance() const {
    return balance;
}
