#include "blockchain.hpp"

Blockchain::Blockchain(Block genesisBlock) {
    chain.emplace_back(genesisBlock);
    difficulty = 3;
}

Block Blockchain::getLastBlock() const{
    return chain.back();
}

void Blockchain::addBlock(Block bNew) {
    bNew.prevHash = getLastBlock().getHash();
    bNew.mineBlock(difficulty);
    chain.push_back(bNew);
}