#include "BankEnor.hpp"
#include <iostream>

int main ()
{
    BankEnor enor("in.txt");
    
    Account richest;
    bool thereIsAnAccountWithA = false;

    for (enor.First(); !enor.End(); enor.Next()) {
        
        bool hasA = false;
        for (int i = 0; i < enor.Current().name.size(); i++) {
            if ('A' == enor.Current().name[i] || 'a' == enor.Current().name[i]) {
                
                hasA = true;
                if (!thereIsAnAccountWithA) {
                    richest = enor.Current();
                    thereIsAnAccountWithA = true;
                }
                
                break;
            }
        }

        if (hasA && enor.Current().balance > richest.balance) {
            richest = enor.Current();
        }
    }

    if (thereIsAnAccountWithA) {
        std::cout << richest.name << " " << richest.balance << std::endl;
    }
    else {
        std::cout << "Nobody has 'a' or 'A' in their name." << std::endl;
    }

    return 0;
}