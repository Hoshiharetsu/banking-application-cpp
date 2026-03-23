#include "Banking.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Banking::Banking()
    : totalBalance(0.0),
    interestEarned(0.0),
    yearlyInterest(0.0),
    monthlyDeposit(0.0),
    annualInterest(0.0),
    years(0) {
}

Banking::Banking(double initialInvestment, double monthlyDepositAmt, double annualInterestRate, int numYears)
    : totalBalance(initialInvestment),
    interestEarned(0.0),
    yearlyInterest(0.0),
    monthlyDeposit(monthlyDepositAmt),
    annualInterest(annualInterestRate),
    years(numYears) {
}

// Setters
void Banking::setInitialInvestment(double amount) { totalBalance = amount; }
void Banking::setMonthlyDeposit(double amount) { monthlyDeposit = amount; }
void Banking::setInterestRate(double rate) { annualInterest = rate; }
void Banking::setYears(int numYears) { years = numYears; }

// Getters
double Banking::getInitialInvestment() const { return totalBalance; }
double Banking::getMonthlyDeposit()    const { return monthlyDeposit; }
double Banking::getInterestRate()      const { return annualInterest; }
int    Banking::getYears()             const { return years; }

// Report: Without monthly deposit
double Banking::balanceWithoutMonthly(double initialInvestment, double annualInterestRate, int numYears) {
    totalBalance = initialInvestment;

    cout << "\n     Balance and Interest Without Additional Monthly Deposits\n";
    cout << string(66, '=') << "\n";
    cout << "Year          Year End Balance          Year End Earned Interest\n";
    cout << string(66, '-') << "\n";

    for (int i = 0; i < numYears; ++i) {
        interestEarned = totalBalance * (annualInterestRate / 100.0);
        totalBalance += interestEarned;
        
        cout << " " << left << setw(5) << (i + 1)
             << "\t\t$ " << fixed << setprecision(2) << totalBalance
             << "\t\t\t\t$" << interestEarned << "\n";
    }
    return totalBalance;
}

// Report: With monthly deposit
double Banking::balanceWithMonthly(double initialInvestment, double monthlyDepositAmt, double annualInterestRate, int numYears) {
    totalBalance = initialInvestment;

    cout << "\n     Balance and Interest With Additional Monthly Deposits\n";
    cout << string(66, '=') << "\n";
    cout << "Year          Year End Balance          Year End Earned Interest\n";
    cout << string(66, '-') << "\n";

    for (int i = 0; i < numYears; ++i) {
        yearlyInterest = 0.0;
        for (int j = 0; j < 12; ++j) {
            double monthlyRate = (annualInterestRate / 100.0) / 12.0;
            interestEarned = (totalBalance + monthlyDepositAmt) * monthlyRate;
            yearlyInterest += interestEarned;
            totalBalance += monthlyDepositAmt + interestEarned;
        }
        
        cout << " " << left << setw(5) << (i + 1)
             << "\t\t$" << fixed << setprecision(2) << totalBalance
             << "\t\t\t\t$" << yearlyInterest << "\n";
    }
    return totalBalance;
}