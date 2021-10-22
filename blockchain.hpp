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

Blockchain::Blockchain(Block genesisBlock) {
    chain.emplace_back(genesisBlock);
    difficulty = 4;
}

Block Blockchain::getLastBlock() const{
    return chain.back();
}

void Blockchain::addBlock(Block bNew) {
    bNew.prevHash = getLastBlock().getHash();
    bNew.mineBlock(difficulty);
    chain.push_back(bNew);
}