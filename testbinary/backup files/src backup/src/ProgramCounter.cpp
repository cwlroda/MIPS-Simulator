#include "include/ProgramCounter.hpp"

void programCounter::increment(){
    if(delayslot == 0){
        ProgCount+=4;
    }

    else{
        delayslot = 0;
    }
}