#ifndef MEM_TRANS_BLOCK_HH
#define MEM_TRANS_BLOCK_HH

    // DDR5 Configuration
    #define SUBCHANNEL_WIDTH               40 // (32 + 8) for DDR5 ECC Subchannel
    #define BURST_LENGTH                   16 // 16 burst length -> 32 * 16 = 64B Cacheline size

    typedef enum {
        NE, // No Error
        CE, // Correctable Error
        DUE, // Detectedu but Uncorrected Error
        SDC, // Silent Data Corruption
    } Decodingresult;

    


    class MemTransferBlcok {
        public:
            // inject error within each codeword
            void random_data_generate();
            void random_onebit_err_injection();
            void random_twobit_err_injection();
            void random_more_than_three_bit_err_injection();

            void SECDED_encode();
            Decodingresult SECDED_decode();
            
            void clear();

        private:
            // consider SECDED configuration
            // 1. how many SECDED_CODEWORDS within memory transfer block?
            // 2. what is SECDED [n, k] configuration per codeword?

    };
#endif