#pragma once
#include <chrono>
#include <sstream>

#include "user.hpp"
#include "transactions.hpp"

using std::vector;
using namespace std::chrono;

class Block{
    public:
        string prevHash;
        int version = 1;
        unsigned int difficulty;
        vector<Transaction> transactions;
        string sHash;
        int index;
        Block(int nIndexIn, vector<Transaction> transaction);
        string getHash();
        string mineBlock(unsigned int difficulty, int allowedAttempts);
        
    private:
        string merkleRootHash;
        int nonce;
        string sData;
        int timestamp = 0;
        string genMerkleRootHash();
        string calculateHash() const;
            
};