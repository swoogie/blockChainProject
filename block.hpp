#pragma once;
#include <chrono>

#include "user.hpp"
#include "transactions.hpp"

using std::vector;
using namespace std::chrono;

class block{
    public:
        int index = 0;
        string prevHash;
        string merkleRootHash;
        unsigned int timestamp = 0;
        int nonce = 0;
        int version = 1;
        int difficulty = 4;
        vector<transaction> transactions;

        block(){
            this->timestamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        }
        void addTransaction(transaction transaction){
            transactions.push_back(transaction);
        }
        void setMerkleRootHash(vector<transaction> transactions){
            
        }
};