#include <iostream>
#include "include/simulator.hpp"
#include "include/memory.hpp"
#include "include/Instructions.hpp"
#include "include/decodeinstruction.hpp"
#include "include/RegisterFile.hpp"
#include "include/ProgramCounter.hpp"
using namespace std;

void simulator::execute(){
    unsigned int binaryinstruction;
    unsigned short decoded1;
    unsigned short decoded2;
    unsigned int decoded3;
    int instructiontype;

    PC.ProgCount = r.ADDR_INSTR_OFFSET;

    while(PC.ProgCount != 0){
        binaryinstruction = r.pullfromMemory(PC.ProgCount);
        instructiontype = decodeinstruction(binaryinstruction, decoded1, decoded2, decoded3);
        insexecute(instructiontype, decoded1, decoded2, decoded3);
        PC.increment();
    }

    try{
        if(PC.ProgCount != 0){
            throw "Internal error!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-20);
    }
}

