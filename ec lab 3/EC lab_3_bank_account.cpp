#include <iostream>
#include <iomanip>
#include <string>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(const std::string& number, const std::string& holder, double initialBalance)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

    virtual ~Account() {}

    const std::string& getAccountNumber() const { return accountNumber; }
    const std::string& getAccountHolder() const { return accountHolder; }
    double getBalance() const { return balance; }

    virtual void displayDetails() const {
        std::cout << "Account Details for " << getAccountType() << " (ID: " << getAccountNumber() << "):" << std::endl;
        std::cout << "   Holder: " << getAccountHolder() << std::endl;
        std::cout << "   Balance: $" << std::fixed << std::setprecision(2) << getBalance() << std::endl;
    }

    virtual std::string getAccountType() const {
        return "Unknown Account";
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double rate)
        : Account(number, holder, initialBalance), interestRate(rate) {}

    double getInterestRate() const { return interestRate; }

    void displayDetails() const override {
        std::cout << "Account Details for " << getAccountType() << " (ID: " << getAccountNumber() << "):" << std::endl;
        std::cout << "   Holder: " << getAccountHolder() << std::endl;
        std::cout << "   Balance: $" << std::fixed << std::setprecision(2) << getBalance() << std::endl;
        std::cout << "   Interest Rate: " << getInterestRate() * 100 << "%" << std::endl;
    }

    void withdraw(double amount) override {
        if (getBalance() - amount >= 100) {
            balance -= amount;
        } else {
            std::cout << "Withdrawal not allowed. Minimum balance of $100 must be maintained." << std::endl;
        }
    }

    std::string getAccountType() const override {
        return "Savings Account";
    }

    // Operator overloading for the + operator to perform the transfer
    friend SavingsAccount& operator+(SavingsAccount& savings, Account& other);
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(const std::string& number, const std::string& holder, double initialBalance, double limit)
        : Account(number, holder, initialBalance), overdraftLimit(limit) {}

    double getOverdraftLimit() const { return overdraftLimit; }

    void displayDetails() const override {
        std::cout << "Account Details for " << getAccountType() << " (ID: " << getAccountNumber() << "):" << std::endl;
        std::cout << "   Holder: " << getAccountHolder() << std::endl;
        std::cout << "   Balance: $" << std::fixed << std::setprecision(2) << getBalance() << std::endl;
        std::cout << "   Overdraft Limit: $" << getOverdraftLimit() << std::endl;
    }

    void withdraw(double amount) override {
        if (getBalance() - amount >= -overdraftLimit) {
            balance -= amount;
        } else {
            std::cout << "Withdrawal not allowed. Overdraft limit exceeded." << std::endl;
        }
    }

    std::string getAccountType() const override {
        return "Current Account";
    }
};

// Operator overloading for the + operator to perform the transfer
SavingsAccount& operator+(SavingsAccount& savings, Account& other) {
    double transferAmount = 300;
    savings.withdraw(transferAmount);
    other.deposit(transferAmount);
    return savings;
}

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);
    std::cout << std::endl;
std::cout << "Account Details after deposit and withdrawal:" << std::endl;
    savings.displayDetails();
    current.displayDetails();

    // Transfer $300 from savings to current
    savings = savings + current;
     std::cout << std::endl;
    std::cout << "Account Details after transfer:" << std::endl;
    savings.displayDetails();
    current.displayDetails();

    return 0;
}
