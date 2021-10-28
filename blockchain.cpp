#include "blockchain.hpp"

Blockchain::Blockchain(Block genesisBlock) {
    chain.emplace_back(genesisBlock);
    difficulty = 3;
}

Block Blockchain::getLastBlock() const{
    return chain.back();
}

string Blockchain::addBlock(int allowedAttempts, Block bNew) {
    bNew.prevHash = getLastBlock().getHash();
    string confirmation = bNew.mineBlock(difficulty, allowedAttempts);
    if(confirmation == "0"){
        return "0";
    }
    else{
        chain.push_back(bNew);
        return "nice";
    }
}