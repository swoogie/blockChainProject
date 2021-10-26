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
        string merkleRootHash;
        int version = 1;
        unsigned int difficulty;
        vector<Transaction> transactions;

        Block(int nIndexIn, vector<Transaction> transactions);
        string getHash();

        void mineBlock(unsigned int difficulty);
        
        private:
            int index;
            int nonce;
            string sData;
            string sHash;
            int timestamp = 0;
            string genMerkleRootHash();
            string calculateHash() const;
};