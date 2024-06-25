#include"MemTransferBlock.hh"
#include<iostream>

int main(void) {
    MemTransferBlcok myblock;

    // 1. SECDED can always correct random 1 bit error
    for(int i = 0; i < 100000; i++) {
        myblock.random_data_generate();
        myblock.SECDED_encode();
        myblock.random_onebit_err_injection();
        
        if(myblock.SECDED_decode() != CE) {
            std::cout << "SECDED should always correct single error" << std::endl;
            exit(1);
        }
    }

    // 2. SECDED can always detect random 2 bit error
    for(int i = 0; i < 100000; i++) {
        myblock.random_data_generate();
        myblock.SECDED_encode();
        myblock.random_twobit_err_injection();
        
        if(myblock.SECDED_decode() != DUE) {
            std::cout << "SECDED should always detect two bit error" << std::endl;
            exit(1);
        }
    }

    // 3. SECDED for more than 3 bit error
    // DIY


    return 0;
}