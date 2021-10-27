#include "transactions.hpp"

Transaction::Transaction(User* publicSender, User* publicReceiver, int amount){
    this->publicSender = publicSender;
    this->publicReceiver = publicReceiver;
    this->senderKey = publicSender->getPublicKey();
    this->receiverKey = publicReceiver->getPublicKey();
    this->amount = amount;
    this->transactionID = hashFun(publicSender->getPublicKey() + publicReceiver->getPublicKey() + to_string(amount));
}