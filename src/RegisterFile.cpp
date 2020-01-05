#include "include/RegisterFile.hpp"

int RegisterFile::readRegister(int RegisterNumber){
    switch(RegisterNumber){
        case 0:
            return $zero;

        case 1:
            return $at;

        case 2:
            return $v0;

        case 3:
            return $v1;

        case 4:
            return $a0;

        case 5:
            return $a1;

        case 6:
            return $a2;

        case 7:
            return $a3;

        case 8:
            return $t0;

        case 9:
            return $t1;

        case 10:
            return $t2;

        case 11:
            return $t3;

        case 12:
            return $t4;

        case 13:
            return $t5;

        case 14:
            return $t6;

        case 15:
            return $t7;

        case 16:
            return $s0;

        case 17:
            return $s1;

        case 18:
            return $s2;

        case 19:
            return $s3;

        case 20:
            return $s4;

        case 21:
            return $s5;

        case 22:
            return $s6;

        case 23:
            return $s7;

        case 24:
            return $t8;

        case 25:
            return $t9;

        case 26:
            return $k0;

        case 27:
            return $k1;

        case 28:
            return $gp;

        case 29:
            return $sp;

        case 30:
            return $fp;

        case 31:
            return $ra;

        case 32:
            return $hi;

        case 33:
            return $lo;
    }
}

void RegisterFile::writeRegister(int RegisterNumber, int input){
    switch(RegisterNumber){
        case 0:
            break;

        case 1:
            $at = input;
            break;

        case 2:
            $v0 = input;
            break;

        case 3:
            $v1 = input;
            break;

        case 4:
            $a0 = input;
            break;

        case 5:
            $a1 = input;
            break;

        case 6:
            $a2 = input;
            break;

        case 7:
            $a3 = input;
            break;

        case 8:
            $t0 = input;
            break;

        case 9:
            $t1 = input;
            break;

        case 10:
            $t2 = input;
            break;

        case 11:
            $t3 = input;
            break;

        case 12:
            $t4 = input;
            break;

        case 13:
            $t5 = input;
            break;

        case 14:
            $t6 = input;
            break;

        case 15:
            $t7 = input;
            break;

        case 16:
            $s0 = input;
            break;

        case 17:
            $s1 = input;
            break;

        case 18:
            $s2 = input;
            break;

        case 19:
            $s3 = input;
            break;

        case 20:
            $s4 = input;
            break;

        case 21:
            $s5 = input;
            break;

        case 22:
            $s6 = input;
            break;

        case 23:
            $s7 = input;
            break;

        case 24:
            $t8 = input;
            break;

        case 25:
            $t9 = input;
            break;

        case 26:
            $k0 = input;
            break;

        case 27:
            $k1 = input;
            break;

        case 28:
            $gp = input;
            break;

        case 29:
            $sp = input;
            break;

        case 30:
            $fp = input;
            break;

        case 31:
            $ra = input;
            break;

        case 32:
            $hi = input;
            break;

        case 33:
            $lo = input;
            break;
    }
}
