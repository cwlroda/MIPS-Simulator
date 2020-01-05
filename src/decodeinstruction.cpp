#include "include/decodeinstruction.hpp"
#include <iostream>
using namespace std;

int decodeinstruction(unsigned int bin, unsigned short& decoded1, unsigned short& decoded2, unsigned int& decoded3){
    unsigned short opcode = bin >> 26;
    //cerr << "opcode is: " << opcode << endl;
    if(opcode == 0){
        unsigned short function = bin & 0b111111;
        unsigned short rs = (bin << 6) >> 27;
        rs = rs & 0b11111;
        unsigned short rt = (bin << 11) >> 27;
        rt = rt & 0b11111;
        unsigned int rd = (bin << 16) >> 27;
        rd = rd & 0b11111;
        unsigned int shamt = (bin << 21) >> 27;
        shamt = shamt & 0b11111;

        switch(function){
            case 1:
                return 0;

            case 0:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = shamt;
                return 1;

            case 2:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = shamt;
                return 2;

            case 3:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = shamt;
                return 3;

            case 4:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = rs;
                return 4;

            case 6:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = rs;
                return 5;

            case 7:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = rs;
                return 6;

            case 8:
                decoded1 = rs;
                return 7;

            case 9:
                decoded1 = rd;
                decoded2 = rs;
                return 8;

            case 12:
                return 9;

            case 16:
                decoded1 = rd;
                return 10;

            case 17:
                decoded1 = rs;
                return 11;

            case 18:
                decoded1 = rd;
                return 12;

            case 19:
                decoded1 = rs;
                return 13;

            case 24:
                decoded1 = rs;
                decoded2 = rt;
                return 14;

            case 25:
                decoded1 = rs;
                decoded2 = rt;
                return 15;

            case 26:
                decoded1 = rs;
                decoded2 = rt;
                return 16;

            case 27:
                decoded1 = rs;
                decoded2 = rt;
                return 17;

            case 32:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 18;

            case 33:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 19;

            case 34:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 20;

            case 35:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 21;

            case 36:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 22;

            case 37:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 23;

            case 38:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 24;

            case 42:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 25;

            case 43:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 26;

            default:
                try{
                    throw "Invalid instruction!";
                } catch(const char* msg){
                    cerr << msg << endl;
                }

                exit(-12);
        }
    }
    else if (opcode == 2 || opcode == 3){
        unsigned int address;
        address = bin & 0x3FFFFF;

        decoded3 = address;
        switch(opcode){
            case 2:
                return 30;

            case 3:
                return 31;

            default:
                try{
                    throw "Invalid instruction!";
                } catch(const char* msg){
                    cerr << msg << endl;
                }

                exit(-12);
        }
    }
    else{
        unsigned short rs = (bin << 6) >> 27;
        rs = rs & 0b11111;
        unsigned short rt = (bin << 11) >> 27;
        rt = rt & 0b11111;
        unsigned int imm = bin & 0xFFFF;

        switch (opcode){
            case 1:
                switch(rt){
                    case 1:
                        decoded1 = rs;
                        decoded3 = imm;
                        return 40;

                    case 17:
                        decoded1 = rs;
                        decoded3 = imm;
                        return 41;

                    case 0:
                        decoded1 = rs;
                        decoded3 = imm;
                        return 42;

                    case 16:
                        decoded1 = rs;
                        decoded3 = imm;
                        return 43;

                    default:
                        try{
                            throw "Invalid instruction!";
                        } catch(const char* msg){
                            cerr << msg << endl;
                        }

                        exit(-12);
                }
            case 4:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 44;

            case 5:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 45;

            case 6:
                decoded1 = rs;
                decoded3 = imm;
                return 46;

            case 7:
                decoded1 = rs;
                decoded3 = imm;
                return 47;

            case 8:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 48;

            case 9:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 49;

            case 10:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 50;

            case 11:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 51;

            case 12:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 52;

            case 13:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 53;

            case 14:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 54;

            case 15:
                decoded1 = rt;
                decoded3 = imm;
                return 55;

            case 32:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 56;

            case 33:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 57;

            case 35:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 58;

            case 34:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 59;

            case 38:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 60;

            case 36:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 61;

            case 37:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 62;

            case 40:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 63;

            case 41:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 64;

            case 43:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 65;

            default:
                try{
                    throw "Invalid instruction!";
                } catch(const char* msg){
                    cerr << msg << endl;
                }

                exit(-12);
        }
    }
}