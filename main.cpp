#include <cstdint>
#include <iostream>
#include <vector>

#include "user.hpp"
#include "rng.hpp"
#include "hashing.hpp"

using namespace std;

int main(){
    for(int i=0; i<1000; i++){
        vector<user> listOfUsers;
        string name = "user" + to_string(i+1);
        int balance = getRandomInteger(100,1000000);
        string publicKey;
        for(int i=0; i<getRandomInteger(4,16); i< i++){
            publicKey += char(getRandomInteger(33, 126));
        }
        publicKey = hashFun(publicKey);
        user newUser(name, publicKey, balance);
        listOfUsers.push_back(newUser);
    }
}
