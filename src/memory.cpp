#include "include/memory.hpp"
#include <iostream>
#include <cstdlib>

void RAM::loadtoMemory(unsigned char binstr){
    unsigned int addr = ADDR_INSTR_OFFSET + offset;

    try{
        if(addr < ADDR_INSTR_OFFSET || addr >= (ADDR_INSTR_OFFSET + ADDR_INSTR_LENGTH)){
            throw "Accessing out of bounds memory!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }

    memory[offset] = binstr;
    offset++;
}

unsigned int RAM::pullfromMemory(unsigned int& ProgCount){
    unsigned int data;

    if((ProgCount-1) == (ADDR_INSTR_OFFSET + offset)){
        ProgCount = 0;
        return 1;
    }

    try{
        if(ProgCount < ADDR_INSTR_OFFSET || ProgCount > (ADDR_INSTR_OFFSET + offset + 4)){
            throw "Accessing out of bounds memory!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }

    unsigned int addr = ProgCount - ADDR_INSTR_OFFSET;

    try{
        if(ProgCount%4 == 0){
            data = (((unsigned int)memory[addr] << 8) + (unsigned int)memory[addr+1]) << 8;
            data = (data + (unsigned int)memory[addr+2]) << 8;
            data = data + (unsigned int)memory[addr+3];
        }

        else{
            throw "Invalid address!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }

    return data;
}

unsigned int RAM::get_addr(){
    return (ADDR_INSTR_OFFSET + offset);
}

void RAM::loadtoDataMem(unsigned int addr, unsigned int data, int num){
    try{
        if(addr < ADDR_DATA_OFFSET || addr >= (ADDR_DATA_OFFSET + ADDR_DATA_LENGTH)){
            throw "Accessing out of bounds memory!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }

    unsigned int lsb = data << 24 >> 24;
    unsigned int xlsb = data << 16 >> 24;
    unsigned int xmsb = data << 8 >> 24;
    unsigned int msb = data >> 24;

    unsigned int index = addr - ADDR_DATA_OFFSET;

    if(num == 0){
        datamem[index] = lsb;
    }

    else if(num == 1){
        try{
            if(addr%2 == 0){
                datamem[index] = xlsb;
                datamem[index+1] = lsb;
            }

            else{
                throw "Invalid address!";
            }
        } catch(const char* msg){
            cerr << msg << endl;
            exit(-11);
        }
    }

    else if(num == 2){
        try{
            if(addr%4 == 0){
                datamem[index] = msb;
                datamem[index+1] = xmsb;
                datamem[index+2] = xlsb;
                datamem[index+3] = lsb;
            }

            else{
                throw "Invalid address!";
            }
        } catch(const char* msg){
            cerr << msg << endl;
            exit(-11);
        }
    }
}

unsigned int RAM::getfromDataMem(unsigned int addr, int num){
    unsigned int data;

    try{
        if((addr < ADDR_DATA_OFFSET) || (addr >= (ADDR_DATA_OFFSET + ADDR_DATA_LENGTH))){
            if((addr < ADDR_INSTR_OFFSET) || (addr >= (ADDR_INSTR_OFFSET + ADDR_INSTR_LENGTH))){
                throw "Accessing out of bounds memory!";
            }
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }

    if((addr & 0x10000000) > 0){
        unsigned int index = addr - ADDR_INSTR_OFFSET;

        if(num == 0){
            data = memory[index];
        }

        else if(num == 1){
            try{
                if(addr%2 == 0){
                    data = (memory[index] << 8) + memory[index+1];
                }

                else{
                    throw "Invalid address!";
                }
            } catch(const char* msg){
                cerr << msg << endl;
                exit(-11);
            }
        }

        else if(num == 2){
            try{
                if(addr%4 == 0){
                    data = ((memory[index] << 8) + memory[index+1]) << 8;
                    data = (data + memory[index+2]) << 8;
                    data = data + memory[index+3];
                }

                else{
                    throw "Invalid address!";
                }
            } catch(const char* msg){
                cerr << msg << endl;
                exit(-11);
            }
        }
    }

    else if((addr & 0x30000000) > 0){
        unsigned int index = addr - ADDR_DATA_OFFSET;

        if(num == 0){
            data = datamem[index];
        }

        else if(num == 1){
            try{
                if(addr%2 == 0){
                    data = (datamem[index] << 8) + datamem[index+1];
                }

                else{
                    throw "Invalid address!";
                }
            } catch(const char* msg){
                cerr << msg << endl;
                exit(-11);
            }
        }

        else if(num == 2){
            try{
                if(addr%4 == 0){
                    data = ((datamem[index] << 8) + datamem[index+1]) << 8;
                    data = (data + datamem[index+2]) << 8;
                    data = data + datamem[index+3];
                }

                else{
                    throw "Invalid address!";
                }
            } catch(const char* msg){
                cerr << msg << endl;
                exit(-11);
            }
        }
    }

    return data;
}

int RAM::getc(int num){
    if(num == 0){
        int x;

        try{
            x = getchar();

            if(cin.fail()){
                throw "I/O error!";
            }
        } catch(const char* msg){
            cerr << msg << endl;
            exit(-21);
        }

        if(x == -1){
            return -1;
        }

        else{
            return 0;
        }
    }

    else if(num == 1){
        int x;

        try{
            x = getchar();

            if(cin.fail()){
                throw "I/O error!";
            }
        } catch(const char* msg){
            cerr << msg << endl;
            exit(-21);
        }

        return x;
    }
}

void RAM::putc(int num, char ch){
    if(num == 0){
        char ch = 0;

        try{
            putchar(ch);

            if(cout.fail()){
                throw "I/O error!";
            }
        } catch(const char* msg){
            cerr << msg << endl;
            exit(-21);
        }
    }

    else if(num == 1){
        try{
            putchar(ch);

            if(cout.fail()){
                throw "I/O error!";
            }
        } catch(const char* msg){
            cerr << msg << endl;
            exit(-21);
        }
    }
}