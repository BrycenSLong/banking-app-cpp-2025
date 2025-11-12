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
        std::string ownerDOB;
    public:
        // Constructor to initialize an object.
        BankAccount(int accNum, const std::string& first, const std::string& last, const std::string& dob, double initialBalance);

        // Method to add funds.
        void deposit(int accNum, double initialBalance);
        
        // Method to add remove funds.
        void withdraw(double amount);
        
        // Method to get the current balance. 
        double getBalance() const;

        // Define Public Getters? What the hell is even that?
        int getAccountNumber() const { return accountNumber; }
        std::string getOwnerFirstName() const { return ownerFirstName; }
        char getOwnerMiddleAnitial() const { return ownerMiddleAnitial; }
        std::string getOwnerLastName() const { return ownerLastName; }
        
};

#endif // BANKACCOUNT_H