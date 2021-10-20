#pragma once

#include <iostream>
#include <vector>

using std::string;

class user{
    public: 
    string name;
    string publicKey;
    int balance;

    user(string name, string publicKey, int balance);

    string getName;
    string getPublicKey;
    string getBalance;
};

user::user(string name, string publicKey, int balance){
    this->name = name;
    this->publicKey = publicKey;
    this->balance = balance;
}

