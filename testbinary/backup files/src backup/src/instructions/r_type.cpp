#include "../include/Instructions.hpp"
#include "../include/memory.hpp"
#include "../include/RegisterFile.hpp"
#include "../include/ProgramCounter.hpp"
#include <iostream>
using namespace std;

void sll(unsigned short& rd, unsigned short rt, unsigned short shamt){
    reg.writeRegister(rd, reg.readRegister(rt) << shamt);
}

void srl(unsigned short& rd, unsigned short rt, unsigned short shamt){
    reg.writeRegister(rd, (unsigned)reg.readRegister(rt) >> shamt);
}

void sra(unsigned short& rd, unsigned short rt, unsigned short shamt){
    if((reg.readRegister(rt) & 0x80000000) > 0){
        int temp = reg.readRegister(rt) >> shamt;
        int sign = 0;

        for(int i=0; i<shamt; i++){
            sign++;
            sign = sign << 1;
        }
        sign = sign << (31-shamt);

        reg.writeRegister(rd, temp | sign);
    }

    else{
        reg.writeRegister(rd, reg.readRegister(rt) >> shamt);
    }
}

void sllv(unsigned short& rd, unsigned short rt, unsigned short rs){
    reg.writeRegister(rd, reg.readRegister(rt) << (reg.readRegister(rs) & 0x1F));
}

void srlv(unsigned short& rd, unsigned short rt, unsigned short rs){
    reg.writeRegister(rd, (unsigned)reg.readRegister(rt) >> (reg.readRegister(rs) & 0x1F));
}

void srav(unsigned short& rd, unsigned short rt, unsigned short rs){
    if((reg.readRegister(rt) & 0x80000000) > 0){
        int temp = reg.readRegister(rt) >> (reg.readRegister(rs) & 0x1F);
        int sign = 0;

        for(int i=0; i<reg.readRegister(rs); i++){
            sign++;
            sign = sign << 1;
        }
        sign = sign << (31-(reg.readRegister(rs) & 0x1F));

        reg.writeRegister(rd, temp | sign);
    }

    else{
        reg.writeRegister(rd, reg.readRegister(rt) >> (reg.readRegister(rs) & 0x1F));
    }
}

void jr(unsigned short rs){
    try{
        if((reg.readRegister(rs)%4 == 0 && reg.readRegister(rs) >= 0x10000000 && reg.readRegister(rs) < r.get_addr()) || reg.readRegister(rs) == 0){
            unsigned int nPC = reg.readRegister(rs);
            delayins();
            PC.ProgCount = nPC;
        }

        else{
            throw "Invalid address!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }
}

void jalr(unsigned short& rd, unsigned short rs){
    if(rd == 0){
        rd = 31;
    }

    try{
        if((reg.readRegister(rs)%4 == 0 && reg.readRegister(rs) >= 0x10000000 && reg.readRegister(rs) < r.get_addr()) || reg.readRegister(rs) == 0){
            reg.writeRegister(rd, PC.ProgCount+8);
            unsigned int nPC = reg.readRegister(rs);
            delayins();
            PC.ProgCount = nPC;
        }

        else{
            throw "Invalid address!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }
}

void mfhi(unsigned short& rd){
    reg.writeRegister(rd, reg.readRegister(32));
}

void mthi(unsigned short rs){
    reg.writeRegister(32, reg.readRegister(rs));
}

void mflo(unsigned short& rd){
    reg.writeRegister(rd, reg.readRegister(33));
}

void mtlo(unsigned short rs){
    reg.writeRegister(33, reg.readRegister(rs));
}

void mult(unsigned short rs, unsigned short rt){
    long xs = reg.readRegister(rs);
    long xt = reg.readRegister(rt);

    long product = xs * xt;

    reg.writeRegister(32, (product & 0xFFFFFFFF00000000) >> 32);
    reg.writeRegister(33, product & 0xFFFFFFFF);
}

void multu(unsigned short rs, unsigned short rt){
    unsigned long xs = (unsigned)reg.readRegister(rs);
    unsigned long xt = (unsigned)reg.readRegister(rt);
    long product = xs * xt;
    reg.writeRegister(32, (product & 0xFFFFFFFF00000000) >> 32);
    reg.writeRegister(33, (product & 0xFFFFFFFF));
}

void div(unsigned short rs, unsigned short rt){
    if(reg.readRegister(rt) != 0){
        int xs = reg.readRegister(rs);
        int xt = reg.readRegister(rt);
        bool s=0, t=0;

        if((reg.readRegister(rs) & 0x80000000) > 1){
            xs = -reg.readRegister(rs);
            s=1;
        }

        if((reg.readRegister(rt) & 0x80000000) > 1){
            xt = -reg.readRegister(rt);
            t=1;
        }

        signed int quotient = xs / xt;
        signed int remainder = xs % xt;

        if((s & t) == 1){
            remainder = -remainder;
        }

        else if(s == 1 && t == 0){
            quotient = -quotient;
            remainder = -remainder;
        }

        else if(s == 0 && t == 1){
            quotient = -quotient;
        }

        reg.writeRegister(33, quotient);
        reg.writeRegister(32, remainder);
    }
}

void divu(unsigned short rs, unsigned short rt){
    if(reg.readRegister(rt) != 0){
        unsigned int quotient = (unsigned)reg.readRegister(rs) / (unsigned)reg.readRegister(rt);
        unsigned int remainder = (unsigned)reg.readRegister(rs) % (unsigned)reg.readRegister(rt);

        reg.writeRegister(33, quotient);
        reg.writeRegister(32, remainder);
    }
}

void add(unsigned short& rd, unsigned short rs, unsigned short rt){
    int32_t xs, xt, sum;

    xs = reg.readRegister(rs);
    xt = reg.readRegister(rt);
    sum = xs+xt;

    /*if(((reg.readRegister(rs) & 0x80000000) > 0) && ((reg.readRegister(rt)) & 0x80000000) > 0){
        xs = -reg.readRegister(rs);
        xt = -reg.readRegister(rt);
        sum = xs+xt;

        if(sum > (unsigned)0x80000000 || sum == 0){
            cerr << "Arithmetic error!" << endl;
            exit(-10);
        }

        else{
            reg.writeRegister(rd, -sum);
        }
    }

    else{
        reg.writeRegister(rd, reg.readRegister(rs) + reg.readRegister(rt));
    }*/

    reg.writeRegister(rd, reg.readRegister(rs) + reg.readRegister(rt));

    cerr << "sum is" << hex << sum << dec << endl;

    if(((xs > 0) && (xt > 0) && (sum < 0)) || ((xs < 0) && (xt < 0) && (sum >= 0))){
        cerr << "Arithmetic error!" << endl;
        exit(-10);
    }
}

void addu(unsigned short& rd, unsigned short rs, unsigned short rt){
    reg.writeRegister(rd, (unsigned)reg.readRegister(rs) + (unsigned)reg.readRegister(rt));
}

void sub(unsigned short& rd, unsigned short rs, unsigned short rt){
    if(reg.readRegister(rs) == 0 && reg.readRegister(rt) == 0x80000000){
        cerr << "Arithmetic error!" << endl;

        exit(-10);
    }

    signed int diff = reg.readRegister(rs) - reg.readRegister(rt);

    if(((reg.readRegister(rs) & 0x80000000) > 0) && ((reg.readRegister(rt) & 0x80000000) == 0) && ((diff & 0x80000000) == 0)){
        cerr << "Arithmetic error!" << endl;
        exit(-10);
    }

    else if(((reg.readRegister(rs) & 0x80000000) == 0) && ((reg.readRegister(rt) & 0x80000000) > 0) && ((diff & 0x80000000) > 0)){
        cerr << "Arithmetic error!" << endl;
        exit(-10);
    }

    reg.writeRegister(rd, diff);
}

void subu(unsigned short& rd, unsigned short rs, unsigned short rt){
    reg.writeRegister(rd, (reg.readRegister(rs) - reg.readRegister(rt)));
}

void andd(unsigned short& rd, unsigned short rs, unsigned short rt){
    reg.writeRegister(rd, (reg.readRegister(rs) & reg.readRegister(rt)));
}

void orr(unsigned short& rd, unsigned short rs, unsigned short rt){
    reg.writeRegister(rd, (reg.readRegister(rs) | reg.readRegister(rt)));
}

void xorr(unsigned short& rd, unsigned short rs, unsigned short rt){
    reg.writeRegister(rd, (reg.readRegister(rs) ^ reg.readRegister(rt)));
}

void slt(unsigned short& rd, unsigned short rs, unsigned short rt){
    if((signed)reg.readRegister(rs) < (signed)reg.readRegister(rt)){
        reg.writeRegister(rd, 1);
    }

    else{
        reg.writeRegister(rd, 0);
    }
}

void sltu(unsigned short& rd, unsigned short rs, unsigned short rt){
    if((unsigned)reg.readRegister(rs) < (unsigned)reg.readRegister(rt)){
        reg.writeRegister(rd, 1);
    }

    else{
        reg.writeRegister(rd, 0);
    }
}
