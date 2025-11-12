#include "bankAccount.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits> // Used for clearing input buffer


void runAccountMenu(BankAccount& account) {
    int choice = 0;
    while (true) {
        std::cout << "\n --- Account Menu ---" << std::endl;
        std::cout << "(1) Veiw Balance" << std::endl;
        std::cout << "(2) Deposit Funds" << std::endl;
        std::cout << "(3) Withdraw Funds" << std::endl;
        std::cout << "(4) Logout" << std::endl;
        std::cout << "Please select an option: " << std::endl;
        std::cin >> choice;

        // Clear buffer after reading the menu choice
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                std::cout << "Current Balance: $" << account.getBalance() << std::endl;
                break;
            case 2:
                // Call a deposit function that will need written later
                std::cout << "Deposit feature coming soon!" << std::endl;
                break;
            case 3:
                // Call a withdraw function that will need written later
                std::cout << "Withdraw feature coming soon!" << std::endl;
                break;
            case 4:
                std::cout << "Logging out..." << std::endl;
                return;
            default:
                std::cerr << "Error: Invalid option. Please try again." << std::endl;
        }

    }
}

int generateAccountNumber() {
    // Bullshit this number for now.
    return 1001;
}


void CreateAccount() {
    
    std::string DOB; // Date of birth input variable
    std::string lastName;
    std::string firstName; // I think this is supposed to be stored as a string? Hopefully no fuck-ups
    double initialDeposit;

    std::cout << "\n--- Create Your Account ---\n";

    // Clear the input buffer before using getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Enter inputs for prompts
    std::cout << "Enter your first name: " << std::endl;
    std::getline(std::cin, firstName);
    std::cout << "Enter your last name: " << std::endl;
    std::getline(std::cin, lastName);
    std::cout << "Enter your date of birth: " << std::endl;
    std::getline(std::cin, DOB);

    // Initial ammount input logic
    std::cout << "Enter your initial deposit amount: $" << std::endl;
    // For numbers we can still use >>
    while(!(std::cin >> initialDeposit)) {
        std::cerr << "Invalid ammount. Please enter a number. \n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter initial deposit amount: $" << std::endl;
    }

    // Get the required data for the constructor
    int accNum = generateAccountNumber();

    // Push inputs into bank account function, and hope this bastard works.
    BankAccount newAccount(accNum, firstName, lastName, DOB, initialDeposit);
  
    std::cout << "\nAccount creation successful! Welcome, " << newAccount.getOwnerFirstName() << " " << newAccount.getOwnerLastName() << "\n";

    // Save new account details to the accounts.txt file like a skid
    std::ofstream outFile("accounts.txt", std::ios::app);

    if(outFile.is_open()) {
        outFile << newAccount.getAccountNumber() << ","
                << newAccount.getOwnerFirstName() << ","
                << newAccount.getOwnerLastName() << ","
                << newAccount.getBalance() << "\n";
        outFile.close();
        std::cout << "Details saved to accoutns.txt\n"; 
    } else {
        std::cerr << "Error: Unable to open accounts.txt for saving.\n";
    }
}

bool authenticate(const std::string& username, const std::string& password) {
    // Important note: This is sketchier as shit and should not be used in a real application.
    // Fix this bitch later!
    std::ifstream file("accounts.txt");

    if (!file.is_open()) {
        std::cerr << "Error: Could not Open Credidentials file." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string stored_username, stored_password;

        // Read the username until the delimiter ';'
        // MUST provide the third Argument: the delimiter character ';'
        std::getline(ss, stored_username, ';');

        // Read the rest of the line as the password
        std::getline(ss, stored_password);

        if (stored_username == username && stored_password == password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}


int main() {
    // Have a welcome message and prompt the user with options
    std::cout << "Welcome to the Banking App!" << std::endl;
    std::cout << "Please select an option: " << std::endl;
    std::cout << "(1)Login" << std::endl;
    std::cout << "(2)Create an account" << std::endl;
    int userInput; // Define this peice of shit first
    std::cin >> userInput;

    if (userInput != 1 && userInput != 2) {
        std::cerr << "Error: Invalid input. Please try again." << std::endl;
        return 1;


        // Bank Account login logic
    } else if(userInput == 1) {
        //---ADD LOGIN FEATURE---
        // Clear the input buffer of any leftover characters(like newlines)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        // Enter in login credentials (gimme that shit)
        std::string username, password;
        std::cout << "Enter Credidentials. " << std::endl;

        std::cout << "Username: ";
        std::getline(std::cin, username);

        std::cout << "Password: ";
        std::getline(std::cin, password);








        // --- Broken ASF ---
        // Check this hoe and make sure nothing breaks
        if (authenticate(username, password)) {
            BankAccount::BankAccount;
            std::cout << "\nLogin successful! Welcome, " << username << "." << std::endl;
            // Fuck, I dont know how to pull the data to keep the program running...
            runAccountMenu(BankAccount);
        } else {
            std::cout  << "\nLogin failed. Invalid Username or password." << std::endl;
        }
        // --- Broken ASF ---
        // --- ADD ACCOUNT FEATURE ---        









        

        // Create an account logic
    } else if(userInput == 2) {
        CreateAccount();


        //---ADD ACCOUNT CREATION FEATURE---
        // std::cout << "Account creation feature is not yet implemented, please try again later," << std::endl;
        std::cout << "(1)Go back to the main menu" << std::endl;
        std::cout << "(2)Exit to the main menu" << std::endl;
        std::cin >> userInput;
        //---ADD ACCOUNT CREATION FEATURE---
        


        if(userInput != 1 && userInput != 2) {
            std::cerr << "Error: Invalid input. Please try again." << std::endl;
            return 1;
        } else if(userInput == 1) { // Back to the main menu
            main();
        } else if(userInput == 2) { // Exit program
            std::cout << "Thank you for using the Banking App. Goodbye!" << std::endl;
            return 0;
        }
    }

    return 0;
}