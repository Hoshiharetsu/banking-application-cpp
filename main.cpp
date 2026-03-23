/*
* CS-210, Project 2
* R. DuPont, Last Update: 10/04/2025
* --------------------------------------------------
* Overview:
* --------------------------------------------------
* Banking Program for users to check their account growth based on 
* inputs for initial value, monthly deposits, interest rate & years.
* Information is presented to the users via a GUI and they have the option
* to run multiple reports.
*/
#include "Banking.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

//--------------------------------------------------
// Banking Methods:
//--------------------------------------------------
void printHomeScreen();
int getValidInt();
double getValidDouble();

//--------------------------------------------------
// Global banking object used across functions
//--------------------------------------------------
Banking myInvestment;

//--------------------------------------------------
// main()
// -------------------------------------------------
// Application entry point.
// Prompts user for investment data, displays both
// balance reports, and allows reruns until quit.
//--------------------------------------------------
int main() {
    char userInput = ' '; //Holder value for tracking user feedback.

    while (userInput != 'q') {
        printHomeScreen(); //Calls to print the UI.

        // Display reports using current account data
        myInvestment.balanceWithoutMonthly(
            myInvestment.getInitialInvestment(),
            myInvestment.getInterestRate(),
            myInvestment.getYears()
        );

        myInvestment.balanceWithMonthly(
            myInvestment.getInitialInvestment(),
            myInvestment.getMonthlyDeposit(),
            myInvestment.getInterestRate(),
            myInvestment.getYears()
        );

        // Prompt to continue or exit
        cout << "\nEnter 'q' to quit, or any other key to run again: ";
        cin >> userInput;
    }

    cout << "Thank you for using our Banking Application. Goodbye!\n";
    return 0;
}

//--------------------------------------------------
// printHomeScreen()
// -------------------------------------------------
// Displays the user input form, validates entries,
// and updates the global Banking object.
//--------------------------------------------------
void printHomeScreen() {
    try {
        cout << "********************************************" << endl;
        cout << "**** Welcome to our Banking Application ****" << endl;
        cout << "********************************************" << endl;

        cout << "Enter your initial investment amount: $";
        double initialInvestment = getValidDouble();
        if (initialInvestment < 0) throw runtime_error("Invalid entry.");
        myInvestment.setInitialInvestment(initialInvestment);

        cout << "Provide your monthly deposit: $";
        double monthlyDeposit = getValidDouble();
        if (monthlyDeposit < 0) throw runtime_error("Invalid entry.");
        myInvestment.setMonthlyDeposit(monthlyDeposit);

        cout << "Enter the annual interest (%): ";
        double annualInterest = getValidDouble();
        if (annualInterest < 0) throw runtime_error("Invalid entry.");
        myInvestment.setInterestRate(annualInterest);

        cout << "Provide the number of years: ";
        int years = getValidInt();
        if (years <= 0) throw runtime_error("Invalid entry.");
        myInvestment.setYears(years);
    }
    catch (runtime_error& error) {
        // Input validation error handling
        cout << "\nError: " << error.what() << endl;
        cout << "Cannot compute with negative or invalid values.\n" << endl;

        printHomeScreen();
    }
}

//--------------------------------------------------
// getValidInt()
// -------------------------------------------------
// Ensures that the user enters a valid integer.
// Keeps prompting until valid input is received.
//--------------------------------------------------
int getValidInt() {
    int value;
    while (true) {
        if (cin >> value) break;
        cout << "Invalid input! Enter a whole number: ";
        cin.clear();
        while (cin.get() != '\n'); // discard bad input
    }
    return value;
}

//--------------------------------------------------
// getValidDouble()
// -------------------------------------------------
// Ensures that the user enters a valid floating-point
// number. Keeps prompting until valid input is entered.
//--------------------------------------------------
double getValidDouble() {
    double value;
    while (true) {
        if (cin >> value) break;
        cout << "Invalid input! Enter a valid number: ";
        cin.clear();
        while (cin.get() != '\n');
    }
    return value;
}