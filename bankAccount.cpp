#include "bankAccount.h"
#include <iostream>
#include <string>

// Default bank account constructor

BankAccount::BankAccount(int accNum, const std::string& first, const std::string& last, const std::string& dob, double initialBalance) { 
    ownerFirstName = first;
    ownerLastName = last;
    ownerDOB = dob;
    balance = initialBalance;
    accountNumber = accNum;

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



