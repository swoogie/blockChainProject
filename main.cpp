#include <cstdint>
#include <iostream>

#include "user.hpp"
#include "rng.hpp"
#include "hashing.hpp"
#include "transactions.hpp"
#include "block.hpp"
#include "blockchain.hpp"

using namespace std;

bool valid(string transactionID, User* publicSender, User* publicReceiver, int amount){
    if (transactionID == hashFun(publicSender->getPublicKey() + publicReceiver->getPublicKey() + to_string(amount))){
        return true;
    }
    else{
        return false;
    }
}

void addTransactionsToBlock(vector<Transaction> &tToBlock, vector<Transaction> &tPool, int &numOfTransactions){
    for(int i=0; i<100; i++){
        int tIndex = getRandomInteger(0,numOfTransactions);
        int tAmount = tPool[tIndex].amount;
        tPool[tIndex].publicSender->balance -= tAmount;
        tPool[tIndex].publicReceiver->balance += tAmount;
        tToBlock.push_back(tPool[tIndex]);
        cout << "Sender key: " << tPool[tIndex].senderKey << " Receiver key: " << tPool[tIndex].receiverKey << " Amount: " << tPool[tIndex].amount << "\n";
        tPool.erase(tPool.begin()+(tIndex));
        numOfTransactions--;
    }
}

int main(){
    vector<User> listOfUsers;
    vector<Transaction> tPool;
    for(int i=0; i<1000; i++){
        string name = "user" + to_string(i+1);
        int balance = getRandomInteger(100,1000000);
        string publicKey;
        for(int i=0; i<getRandomInteger(4,16); i++){
            publicKey += char(getRandomInteger(33, 126));
        }
        publicKey = hashFun(publicKey);
        User newUser(name, publicKey, balance);
        listOfUsers.push_back(newUser);
    }
    
    for(int i=0; i<10000; i++){
        int sIndex = getRandomInteger(0,1000);
        int rIndex = getRandomInteger(0,1000);
        while(sIndex == rIndex){
            sIndex = getRandomInteger(0,1000);
            rIndex = getRandomInteger(0,1000);
        }
        User* sender = &listOfUsers[sIndex];
        User* receiver = &listOfUsers[rIndex];
        int balance = getRandomInteger(0,sender->balance);
        Transaction newTransaction(sender, receiver, balance);
        if(valid(newTransaction.transactionID, sender, receiver, balance)){
            tPool.push_back(newTransaction);
        }
    }

    vector<Transaction> tToBlock[5];
    int numOfTransactions = 10000;
    addTransactionsToBlock(tToBlock[0], tPool, numOfTransactions);
    Block genesisBlock(0, tToBlock[0]);
    Blockchain bChain(genesisBlock);
    int i = 1;
    while(tPool.size()>=100){
        int allowedAttempts = 100000;

        for(int j=0; j<5; j++){
            tToBlock[j].clear();
            addTransactionsToBlock(tToBlock[j], tPool, numOfTransactions);
        }

        cout << "Mining block " << i << "\n";

        string confirmation;
        while(confirmation != "nice"){
            for(int j=0; j<5; j++){ 
                confirmation = bChain.addBlock(allowedAttempts, Block(i, tToBlock[j]));
                    if(confirmation == "nice"){
                        int lastMember = bChain.chain.size();
                        break;
                    }
            }
            allowedAttempts += 100000;
        }
        i++;
    }
    cout << "finished. \n";
    tToBlock[1,2,3,4,5].clear();
}