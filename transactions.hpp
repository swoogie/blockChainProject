#pragma once

#include "user.hpp"
#include "hashing.hpp"

using std::string;
using std::to_string;

class transaction{
    public:
        transaction(user* publicSender, user* publicReceiver, int amount){
        this->publicSender = publicSender;
        this->publicReceiver = publicReceiver;
        this->amount = amount;
        this->transaction_id = hashFun(publicSender->getPublicKey() + publicReceiver->getPublicKey() + to_string(amount));
    }
        string transaction_id;
        user* publicSender;
        user* publicReceiver;
        int amount;
};