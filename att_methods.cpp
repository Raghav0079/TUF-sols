#include <bits/stdc++.h>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    // Parameterized constructor
    BankAccount(string accountNumber, double initialBalance) {
        this->accountNumber = accountNumber;
        if (initialBalance >= 0) {
            this->balance = initialBalance;
        }
        else {
            this->balance = 0.00;
            cout << "Insufficient funds!" << endl;
        }
    }

    // Method to deposit money
    void deposit(double amount) {
        balance += amount;
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    // Method to display account details
    void displayDetails() {
        cout << "Account Number : " << accountNumber << endl;
        cout << fixed << setprecision(2);
        cout << "Balance : " << balance << endl;
    }
};

// Please Do not change anything below, It is only for your reference.
/*
This is the driver code that will execute and demonstrate the functionality of your `BankAccount` class.

It creates a object of class `BankAccount`, the object sets the values of accountNumber and balance using the parameterised constructor.
Then calls the method addBalance to add the balance in the account.
Then it calls the withdrawBalance to withdraw the balance from the account.
At end it displays the details of account using the displayDetails method.


// Main function to demonstrate the functionality of the BankAccount class
int main() {

    string accountNumber;
    getline(cin, accountNumber);
    double balance;
    cin >> balance;

    // Create a BankAccount object with the use of parameterised constructor
    BankAccount account(accountNumber, balance);

    // Deposit money
    double addBalance;
    cin >> addBalance;
    account.deposit(addBalance);

    // Withdraw money
    double withdrawBalance;
    cin >> withdrawBalance;
    account.withdraw(withdrawBalance);

    // Display account details
    account.displayDetails();

    return 0;
}
*/

/*
// Below is the output statements

cout << "Insufficient funds!" << endl;
cout << "Account Number : " << accountNumber << endl;
cout << "Balance : " << balance << endl;
*/
