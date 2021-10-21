#pragma once;
#include <chrono>

#include "user.hpp"
#include "transactions.hpp"

using std::vector;
using namespace std::chrono;

class Block{
    public:
        int index = 0;
        string prevHash;
        string merkleRootHash;
        unsigned int timestamp = 0;
        int nonce = 0;
        int version = 1;
        unsigned int difficulty = 4;
        vector<Transaction> transactions;

        Block(){
            this->timestamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        }
        void addTransaction(Transaction transaction){
            transactions.push_back(transaction);
        }
        void setMerkleRootHash(){
            string newHash;
            for(int i=0; i<transactions.size(); i++){
                newHash += transactions[i].transactionID;
            }
            merkleRootHash = hashFun(newHash);
        }
        void mineBlock(unsigned int difficulty){
            

        }
};