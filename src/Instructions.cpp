#include "include/simulator.hpp"
#include "include/memory.hpp"
#include "include/ProgramCounter.hpp"
#include "include/Instructions.hpp"
#include "include/decodeinstruction.hpp"
#include "include/RegisterFile.hpp"
#include <iostream>
using namespace std;

void insexecute(int instype, unsigned short decoded1, unsigned short decoded2, unsigned int decoded3){
    switch(instype){
        case 0:
            return;

        case 1:
            sll(decoded1, decoded2, decoded3);
            return;

        case 2:
            srl(decoded1, decoded2, decoded3);
            return;

        case 3:
            sra(decoded1, decoded2, decoded3);
            return;

        case 4:
            sllv(decoded1, decoded2, decoded3);
            return;

        case 5:
            srlv(decoded1, decoded2, decoded3);
            return;

        case 6:
            srav(decoded1, decoded2, decoded3);
            return;

        case 7:
            jr(decoded1);
            return;

        case 8:
            jalr(decoded1, decoded2);
            return;

        case 9:
            return;

        //syscall

        case 10:
            mfhi(decoded1);
            return;

        case 11:
            mthi(decoded1);
            return;

        case 12:
            mflo(decoded1);
            return;

        case 13:
            mtlo(decoded1);
            return;

        case 14:
            mult(decoded1, decoded2);
            return;

        case 15:
            multu(decoded1, decoded2);
            return;

        case 16:
            div(decoded1, decoded2);
            return;

        case 17:
            divu(decoded1, decoded2);
            return;

        case 18:
            add(decoded1, decoded2, decoded3);
            return;

        case 19:
            addu(decoded1, decoded2, decoded3);
            return;

        case 20:
            sub(decoded1, decoded2, decoded3);
            return;

        case 21:
            subu(decoded1, decoded2, decoded3);
            return;

        case 22:
            andd(decoded1, decoded2, decoded3);
            return;

        case 23:
            orr(decoded1, decoded2, decoded3);
            return;

        case 24:
            xorr(decoded1, decoded2, decoded3);
            return;

        case 25:
            slt(decoded1, decoded2, decoded3);
            return;

        case 26:
            sltu(decoded1, decoded2, decoded3);
            return;

        case 30:
            j(decoded3);
            return;

        case 31:
            jal(decoded3);
            return;

        case 40:
            bgez(decoded1, decoded3);
            return;

        case 41:
            bgezal(decoded1, decoded3);
            return;

        case 42:
            bltz(decoded1, decoded3);
            return;

        case 43:
            bltzal(decoded1, decoded3);
            return;

        case 44:
            beq(decoded1, decoded2, decoded3);
            return;

        case 45:
            bne(decoded1, decoded2, decoded3);
            return;

        case 46:
            blez(decoded1, decoded3);
            return;

        case 47:
            bgtz(decoded1, decoded3);
            return;

        case 48:
            addi(decoded2, decoded1, decoded3);
            return;

        case 49:
            addiu(decoded2, decoded1, decoded3);
            return;

        case 50:
            slti(decoded2, decoded1, decoded3);
            return;

        case 51:
            sltiu(decoded2, decoded1, decoded3);
            return;

        case 52:
            andi(decoded2, decoded1, decoded3);
            return;

        case 53:
            ori(decoded2, decoded1, decoded3);
            return;

        case 54:
            xori(decoded2, decoded1, decoded3);
            return;

        case 55:
            lui(decoded1, decoded3);
            return;

        case 56:
            lb(decoded1, decoded2, decoded3);
            return;

        case 57:
            lh(decoded1, decoded2, decoded3);
            return;

        case 58:
            lw(decoded1, decoded2, decoded3);
            return;

        case 59:
            lwl(decoded1, decoded2, decoded3);
            return;

        case 60:
            lwr(decoded1, decoded2, decoded3);
            return;

        case 61:
            lbu(decoded1, decoded2, decoded3);
            return;

        case 62:
            lhu(decoded1, decoded2, decoded3);
            return;

        case 63:
            sb(decoded1, decoded2, decoded3);
            return;

        case 64:
            sh(decoded1, decoded2, decoded3);
            return;

        case 65:
            sw(decoded1, decoded2, decoded3);
            return;

        default:
            cerr << "Invalid instruction!" << endl;
            exit(-12);
    }
}

extern void delayins(){
    unsigned int binaryinstruction;
    unsigned short decoded1;
    unsigned short decoded2;
    unsigned int decoded3;
    int instructiontype;
    PC.ProgCount+=4;

    binaryinstruction = r.pullfromMemory(PC.ProgCount);
    instructiontype = decodeinstruction(binaryinstruction, decoded1, decoded2, decoded3);
    insexecute(instructiontype, decoded1, decoded2, decoded3);

    PC.delayslot = 1;
}