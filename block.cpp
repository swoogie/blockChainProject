#include "block.hpp"

Block::Block(int indexIn, vector<Transaction> transactions){
    this->index = indexIn;
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


string Block::mineBlock(unsigned int difficulty, int allowedAttempts){
    char* cstr;
    cstr = new char[difficulty+1];
    for(int i=0; i<difficulty; i++){
        cstr[i] = '0';
    }

    cstr[difficulty] = '\0';
    
    string str(cstr);

    merkleRootHash = genMerkleRootHash();
    int attempts = 0;
    while(sHash.substr(0, difficulty) !=str){
        if(attempts >= allowedAttempts){
            return "0";
            break;
        }
        else{
            nonce++;
            sHash = calculateHash();
            attempts++;
        }
    }
    cout << "Hash of block " << index << ": " << sHash << "\n";
    return "nice";
}