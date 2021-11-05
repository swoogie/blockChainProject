#pragma once

#include <vector>
#include "block.hpp"

using namespace std;

class Blockchain {
    public:
        Blockchain(Block genesisBlock);
        vector<Block> chain;
        string addBlock(int allowedAttempts, Block bNew);

    private:
        unsigned int difficulty;
        
        Block getLastBlock() const;
};