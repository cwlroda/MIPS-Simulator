#ifndef MEMORY_HPP
#define MEMORY_HPP
#include <string>
using namespace std;

class RAM{
    public:
        static const unsigned int ADDR_NULL_OFFSET = 0x00000000;
        static const unsigned int ADDR_NULL_LENGTH = 0x4;
        static const unsigned int ADDR_INSTR_OFFSET = 0x10000000;
        static const unsigned int ADDR_INSTR_LENGTH = 0x1000000;
        static const unsigned int ADDR_DATA_OFFSET = 0x20000000;
        static const unsigned int ADDR_DATA_LENGTH = 0x4000000;
        static const unsigned int ADDR_GETC_OFFSET = 0x30000000;
        static const unsigned int ADDR_GETC_LENGTH = 0x4;
        static const unsigned int ADDR_PUTC_OFFSET = 0x30000004;
        static const unsigned int ADDR_PUTC_LENGTH = 0x4;

        unsigned char memory[16777216] = {0};
        int datamem[67108864] = {0};

        void loadtoMemory(unsigned char binstr);
        unsigned int pullfromMemory(unsigned int& ProgCount);
        unsigned int get_addr();
        void loadtoDataMem(unsigned int addr, unsigned int data, int num);
        unsigned int getfromDataMem(unsigned int addr, int num);

        int getc(int num);
        void putc(int num, char ch);

        string line;
        bool eof = 0;

    private:
        unsigned int value;
        unsigned int offset = 0;
};

extern RAM r;

#endif