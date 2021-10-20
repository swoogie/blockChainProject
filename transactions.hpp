#pragma once

#include <iostream>

using std::string;

class transaction{
    public:
        string transaction_id;
        string publicSender;
        string publicReceiver;
        string amount;
    private:
};