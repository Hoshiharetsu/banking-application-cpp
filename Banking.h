#ifndef BANKING_H
#define BANKING_H

//======================================================
// Banking Class Declaration
// -----------------------------------------------------
// Holds info regarding the investment account including: initial
// balance, optional monthly deposits, and annual interest.
// Includes methods to calculate and output yearly balances
// with/without additional monthly contributions.
//======================================================
class Banking {
public:
    // ----- Constructors -----
    Banking();
    Banking(double initialInvestment, double monthlyDeposit,
        double annualInterest, int years);

    // ----- Setters -----
    void setInitialInvestment(double amount);
    void setMonthlyDeposit(double amount);
    void setInterestRate(double rate); // Annual interest in percent
    void setYears(int years);

    // ----- Getters -----
    double getInitialInvestment() const;
    double getMonthlyDeposit() const;
    double getInterestRate() const;
    int    getYears() const;

    // ----- Core Calculations -----
    // Display and calculate yearly balances *without* monthly deposits
    double balanceWithoutMonthly(double initialInvestment,
        double annualInterest, int years);

    // Display and calculate yearly balances *with* monthly deposits
    double balanceWithMonthly(double initialInvestment,
        double monthlyDeposit,
        double annualInterest, int years);

    // Convenience overloads using stored values
    double balanceWithoutMonthly();
    double balanceWithMonthly();

private:
    double totalBalance;     // Running account balance
    double interestEarned;   // Last calculated interest value
    double yearlyInterest;   // Accumulated interest for a full year
    double monthlyDeposit;   // Fixed deposit added each month
    double annualInterest;   // Annual percentage rate (APR)
    int    years;            // Duration of investment in years
};

#endif // BANKING_H