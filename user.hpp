#pragma once

#include <iostream>
#include <vector>

using std::string;

class User{
    public: 
    User(string name, string publicKey, int balance);
    string getName();
    string getPublicKey();
    int getBalance();
    int balance;
    private:
    string name;
    string publicKey;
};
