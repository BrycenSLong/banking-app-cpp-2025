#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

// IDK if I fucking need this or not
#include <string>

class BankAccount {
    private:
        double balance;
        int accountNumber;
        std::string ownerFirstName;
        char ownerMiddleAnitial;
        std::string ownerLastName;
    public:
        // Constructor to initialize an object.
        BankAccount(int accNum, double initialBalance);

        // Method to add funds.
        void deposit(int accNum, double initialBalance);
        
        // Method to add remove funds.
        void withdraw(double amount);
        
        // Method to get the current balance. 
        double getBalance() const;
};

#endif // BANKACCOUNT_H