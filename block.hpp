#pragma once;
#include <chrono>
#include <sstream>

#include "user.hpp"
#include "transactions.hpp"

using std::vector;
using namespace std::chrono;

class Block{
    public:
        string prevHash;
        string merkleRootHash;
        int version = 1;
        uint64_t difficulty;
        vector<Transaction> transactions;

        Block(int nIndexIn, vector<Transaction> transactions);
        string getHash();

        void addTransaction(Transaction transaction){
            transactions.push_back(transaction);
        }

        void mineBlock(uint64_t difficulty);
        
        private:
            int index;
            int nonce;
            string sData;
            string sHash;
            int timestamp = 0;
            string genMerkleRootHash();
            string calculateHash() const;
};

Block::Block(int indexIn, vector<Transaction> transactions){
    index = indexIn;
    this->transactions = transactions;
    nonce = -1;
    this->timestamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

string Block::getHash(){
    return sHash;
}

string Block::genMerkleRootHash(){
            string newHash;
            for(int i=0; i<transactions.size(); i++){
                newHash += transactions[i].transactionID;
            }
            merkleRootHash = hashFun(newHash);
}

string Block::calculateHash() const{
    stringstream ss;
    ss << index << timestamp << sData << nonce << prevHash;

    return hashFun(ss.str());
}


void Block::mineBlock(uint64_t difficulty){
    char* cstr;
    cstr = new char[difficulty+1];
    for(int i=0; i<difficulty; i++){
        cstr[i] = '0';
    }

    cstr[difficulty] = '\0';

    string str(cstr);

    merkleRootHash = genMerkleRootHash();

    while(sHash.substr(0, difficulty) !=str){
        nonce++;
        sHash = calculateHash();
    }
}