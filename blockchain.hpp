#pragma once

#include <vector>
#include "block.hpp"

using namespace std;

class Blockchain {
    public:
        Blockchain();

        void AddBlock(Block bNew);
    private:
    unsigned int difficulty;
    vector<Block> chain;
    
    Block getLastBlock() const;
}