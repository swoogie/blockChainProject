#include "block.hpp"

Block::Block(int indexIn, vector<Transaction> transactions){
    index = indexIn;
    this->transactions = transactions;
    nonce = -1;
    this->timestamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

string Block::getHash(){
    return sHash;
}

string Block::genMerkleRootHash(){
            string newHash;
            for(int i=0; i<transactions.size(); i++){
                newHash += transactions[i].transactionID;
            }
            return hashFun(newHash);
}

string Block::calculateHash() const{
    stringstream ss;
    ss << index << timestamp << sData << nonce << prevHash;

    return hashFun(ss.str());
}


void Block::mineBlock(unsigned int difficulty){
    char* cstr;
    cstr = new char[difficulty+1];
    for(int i=0; i<difficulty; i++){
        cstr[i] = '0';
    }

    cstr[difficulty] = '\0';
    
    string str(cstr);

    merkleRootHash = genMerkleRootHash();

    while(sHash.substr(0, difficulty) !=str){
        nonce++;
        sHash = calculateHash();
    }
    cout << "Hash of block " << index << ": " << sHash << "\n";
}