#include "../include/Instructions.hpp"
#include "../include/RegisterFile.hpp"
#include "../include/ProgramCounter.hpp"
#include <iostream>
using namespace std;

void j(unsigned int address){
    delayins();
    PC.ProgCount = ((PC.ProgCount & 0xF0000000) | (address << 2));
}

void jal(unsigned int address){
    reg.writeRegister(31, PC.ProgCount+8);
    delayins();
    PC.ProgCount = (PC.ProgCount & 0xF0000000) | (address << 2);
}
