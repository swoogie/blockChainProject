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
            vector<string> merkle;
            for(int i=0; i<transactions.size(); i++){
                merkle.push_back(hashFun(transactions[i].transactionID));
            }
            
            if (merkle.size() % 2 != 0){
                merkle.push_back(merkle.back());
            }
            
            while(merkle.size() > 1){
                vector<string> newMerkle;
                for(int it=0; it < merkle.size(); it += 2){
                    string sNewMerkle = hashFun(merkle[it+1]) + hashFun(merkle[it]);
                    newMerkle.push_back(hashFun(sNewMerkle));
                }

                merkle = newMerkle;
            }

            return merkle[0];
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