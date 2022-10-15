#include <iostream>
#include <string>
using namespace std;
 
 int main()
 {
    double annualInterestRate, balance, totalDeposit, totalWithdrawn, totalInterest;
    annualInterestRate = balance = totalDeposit = totalWithdrawn = totalInterest = 0;

    string annualIR;
    while (annualInterestRate == 0)
    {
        cout << "What is your annual interest rate (e.g., 10%)? \n";
        cin >> annualIR;
        int length = annualIR.size();
        if (annualIR.at(length - 1) == '%') 
        {
            annualInterestRate = stof(annualIR) / 100;
        } 
        else 
        cout << "Please enter the percentage rate with '%' sign (e.g., 10%).\n";
        
    }

    cout << "What is your starting balance? \n$";
    cin >> balance;

    int monthsSinceStart;
    cout << "How many months have passed since the account was established? \n";
    cin >> monthsSinceStart;

    for (int i = 1; i <= monthsSinceStart; i++)
    {
        double currentDeposit = -1;
        while (currentDeposit < 0)
        {
            cout << "How much was deposited in month " << i << "? \n$";
            cin >> currentDeposit;
            if (currentDeposit < 0) {
                cout << "Please enter a value greater than 0.\n";
            }
        }
        balance += currentDeposit;
        totalDeposit += currentDeposit;

        double currentWithdrawal = -1;
        while (currentWithdrawal < 0)
        {
            cout << "How much was withdrawn? \n$";
            cin >> currentWithdrawal;
            if (currentDeposit < 0) {
                cout << "Please enter a value greater than 0.\n";
            }
        }
        balance -= currentWithdrawal;
        totalWithdrawn += currentWithdrawal;

        double monthlyIR = (annualInterestRate / 100) / 12;

        double monthlyInterest = balance * monthlyIR;

        cout << "Monthly interest: \n$" << monthlyInterest << endl;
        balance += monthlyInterest;
        totalInterest += monthlyInterest;
        
        if (balance < 0)
        {
            cout << "Account has been closed " << endl;
            break;
        }
    }

    cout << "\nFinal balance: $" << balance << "\nTotal Amount Deposited: $" << totalDeposit << endl;
    cout << "Total Amount Withdrawn: $" << totalWithdrawn << "\nTotal Interest Earned: $" << totalInterest << endl;
    
    return 0;

 }