#ifndef SEC_DED_HH
#define SEC_DED_HH
    #include"MemTransferBlock.hh"

    class SECDED_Codeword {
        public:
            SECDED_Codeword(); // this constructor will make H-matrix & G-matrix used for decoding & encoding process
            void err_injection(int position);

            void encode();
            Decodingresult decode();
        private:
    }
#endif