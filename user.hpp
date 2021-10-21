#pragma once

#include <iostream>
#include <vector>

using std::string;

class User{
    public: 
    User(string name, string publicKey, int balance);
    string name;
    string publicKey;
    int balance;

    string getName();
    string getPublicKey();
    int getBalance();
};

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