#pragma once

#include "user.hpp"
#include "hashing.hpp"

using std::string;
using std::to_string;

class Transaction{
    public:
        Transaction(User* publicSender, User* publicReceiver, int amount);
        string transactionID;
        User* publicSender;
        User* publicReceiver;
        int amount;

};

Transaction::Transaction(User* publicSender, User* publicReceiver, int amount){
    this->publicSender = publicSender;
        this->publicReceiver = publicReceiver;
        this->amount = amount;
        this->transactionID = hashFun(publicSender->getPublicKey() + publicReceiver->getPublicKey() + to_string(amount));
}