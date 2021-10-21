#include <cstdint>
#include <iostream>


#include "user.hpp"
#include "rng.hpp"
#include "hashing.hpp"
#include "transactions.hpp"
#include "block.hpp"

using namespace std;

int main(){
    vector<user> listOfUsers;
    vector<transaction> pool;
    for(int i=0; i<1000; i++){
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
    
    for(int i=0; i<10000; i++){
        user* sender = &listOfUsers[getRandomInteger(1,1000)];
        user* receiver = &listOfUsers[getRandomInteger(1,1000)];
        transaction newTransaction(sender, receiver, getRandomInteger(0,sender->balance));
        pool.push_back(newTransaction);
    }

    block newBlock;
    for(int i=0; i<100; i++){
        newBlock.addTransaction(pool[getRandomInteger(1,10000)]);
        newBlock.index++;
    }
    newBlock.setMerkleRootHash();
}