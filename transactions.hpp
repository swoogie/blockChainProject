#pragma once

#include "user.hpp"
#include "hashing.hpp"

using std::string;
using std::to_string;

class Transaction{
    public:
        Transaction(User* publicSender, User* publicReceiver, int amount);
        string transactionID;
        string senderKey;
        string receiverKey;
        User* publicSender;
        User* publicReceiver;
        int amount;

};