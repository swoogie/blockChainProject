#pragma once

#include <vector>
#include "block.hpp"

using namespace std;

class Blockchain {
    public:
        Blockchain(Block genesisBlock);

        void addBlock(Block bNew);

    private:
        unsigned int difficulty;
        vector<Block> chain;
        Block getLastBlock() const;
};