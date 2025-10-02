#include "bankAccount.h"
#include <iostream>



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
        std::cout << "Account login feature is not yet implemented." << std::endl;
        std::cout << "(1)Go back to the main menu" << std::endl;
        std::cout << "(2)Exit the program" << std::endl;
        std::cin >> userInput;
        if(userInput != 1 && userInput != 2) {
            std::cerr << "Error: Invalid input. Please try again." << std::endl;
            return 1;
        } else if(userInput == 1) { // Back to the main menu
            main();
        } else if(userInput == 2) { // Exit program
            std::cout << "Thank you for using the Banking App. Goodbye!" << std::endl;
            return 0;
        }
        

        // Create an account logic
    } else if(userInput == 2) {
        std::cout << "Account creation feature is not yet implemented, please try again later," << std::endl;
        std::cout << "(1)Go back to the main menu" << std::endl;
        std::cout << "(2)Exit to the main menu" << std::endl;
        std::cin >> userInput;
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