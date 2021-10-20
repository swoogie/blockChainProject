#pragma once

#include "user.hpp"
#include "hashing.hpp"

using std::string;

class transaction{
    public:
        transaction(user* publicSender, user* publicReceiver, string amount);
        string transaction_id;
        user* publicSender;
        user* publicReceiver;
        string amount;
};

transaction::transaction(user* publicSender, user* publicReceiver, string amount){
    this->publicSender = publicSender;
    this->publicReceiver = publicReceiver;
    this->amount = amount;
    this->transaction_id = hashFun(this->publicSender->getPublicKey() + this->publicReceiver->getPublicKey() + amount);