#ifndef WALLET_H
#define WALLET_H
#include <string>

// 구조체: 기본적으로 멤버가 public임
struct Transaction {
    std::string type;
    int amount;
};

class Wallet {
private:
    std::string owner;
    int balance;
    Transaction lastTx;

public:
    Wallet();
    Wallet(std::string owner);
    Wallet(std::string owner, int balance);

    ~Wallet();

    void deposit(int amount);
    bool withdraw(int amount);
    void print() const;

    inline int getBalance() {
        return balance;
    }
};

#endif