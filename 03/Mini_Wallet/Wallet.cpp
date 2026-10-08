#include <iostream>
#include <string>
#include "Wallet.h"

Wallet::Wallet(std::string owner, int balance) : owner(owner) {
    if (balance < 0) {
        std::cout << "invalid balance" << std::endl;
        this->balance = 0;
    } else {
        this->balance = balance;
    }
    lastTx = {"none", 0};
}

Wallet::Wallet(std::string owner) : Wallet(owner, 0) {}

Wallet::Wallet() : Wallet("none", 0) {}

Wallet::~Wallet(){
    std::cout << "bye " << owner << std::endl;
}

void Wallet::deposit(int amount) {
    if (amount <= 0) return;
    
    balance += amount;
    lastTx = {"deposit", amount};
}

bool Wallet::withdraw(int amount) {
    if (balance < amount) {
        std::cout << "Fail" << std::endl;
        return false;
    }
    
    balance -= amount;
    lastTx = {"withdraw", amount};
    return true;
}

void Wallet::print() const {
    std::cout << "Owner: " << owner << " | Balance: " << balance << std::endl;
    std::cout << "LastTx: " <<  lastTx.amount << std::endl;
}