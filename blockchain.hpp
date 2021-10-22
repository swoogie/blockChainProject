#pragma once

#include <vector>
#include "block.hpp"

using namespace std;

class Blockchain {
    public:
        Blockchain(vector<Transaction> transactions);

        void AddBlock(Block bNew);

    private:
        unsigned int difficulty;
        vector<Block> chain;
        Block getLastBlock() const;
};

Blockchain::Blockchain(vector<Transaction> transactions) {
    chain.emplace_back(Block(0, transactions));
    difficulty = 4;
}

Block Blockchain::getLastBlock() const{
    return chain.back();
}

void Blockchain::AddBlock(Block bNew) {
    bNew.prevHash = getLastBlock().getHash();
    bNew.mineBlock(difficulty);
    chain.push_back(bNew);
}