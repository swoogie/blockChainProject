#include "user.hpp"

User::User(string name, string publicKey, int balance){
    this->name = name;
    this->publicKey = publicKey;
    this->balance = balance;
}

string User::getName(){
    return this->name;
}

string User::getPublicKey(){
    return this->publicKey;
}

int User::getBalance(){
    return this->balance;
}