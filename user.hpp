#pragma once

#include <iostream>
#include <vector>

using std::string;

class user{
    public: 
    user(string name, string publicKey, int balance);
    string name;
    string publicKey;
    int balance;

    string getName();
    string getPublicKey();
    int getBalance();
};

user::user(string name, string publicKey, int balance){
    this->name = name;
    this->publicKey = publicKey;
    this->balance = balance;
}

string user::getName(){
    return this->name;
}

string user::getPublicKey(){
    return this->publicKey;
}

int user::getBalance(){
    return this->balance;
}