#include <cstdint>
#include <iostream>


#include "user.hpp"
#include "rng.hpp"
#include "hashing.hpp"
#include "transactions.hpp"
#include "block.hpp"
#include "blockchain.hpp"

using namespace std;

int main(){
    vector<User> listOfUsers;
    vector<Transaction> tPool;
    for(int i=0; i<1000; i++){
        string name = "user" + to_string(i+1);
        int balance = getRandomInteger(100,1000000);
        string publicKey;
        for(int i=0; i<getRandomInteger(4,16); i< i++){
            publicKey += char(getRandomInteger(33, 126));
        }
        publicKey = hashFun(publicKey);
        User newUser(name, publicKey, balance);
        listOfUsers.push_back(newUser);
    }
    
    for(int i=0; i<10000; i++){
        User* sender = &listOfUsers[getRandomInteger(1,1000)];
        User* receiver = &listOfUsers[getRandomInteger(1,1000)];
        Transaction newTransaction(sender, receiver, getRandomInteger(0,sender->balance));
        tPool.push_back(newTransaction);
    }

    vector<Transaction> tToBlock;
    for(int i=0; i<100; i++){
        int tIndex = getRandomInteger(1,10000);
        tToBlock.push_back(tPool[tIndex]);
        int senderBalance = tPool[tIndex].publicSender->balance;
        int receiverBalance = tPool[tIndex].publicReceiver->balance;
        int tAmount = tPool[tIndex].amount;
        tPool.erase(tPool.begin()+(tIndex-1));
        senderBalance -= tAmount;
        receiverBalance += tAmount;

    

    Block genesisBlock(0, tToBlock);
    Blockchain bChain(genesisBlock);



    bChain.addBlock(Block(1, tToBlock));

    //newBlock.setMerkleRootHash();
}