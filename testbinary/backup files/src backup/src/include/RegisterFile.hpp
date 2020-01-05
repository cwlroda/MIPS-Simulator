#ifndef REGISTERFILE_HPP
#define REGISTERFILE_HPP

class RegisterFile{
    public:
        int readRegister(int RegisterNumber);
        void writeRegister(int RegisterNumber, int input);

    private:
        int $zero = 0;
        int $at = 0;
        int $v0 = 0, $v1 = 0;
        int $a0 = 0, $a1 = 0, $a2 = 0, $a3 = 0;
        int $t0 = 0, $t1 = 0, $t2 = 0, $t3 = 0, $t4 = 0, $t5 = 0, $t6 = 0, $t7 = 0;
        int $s0 = 0, $s1 = 0, $s2 = 0, $s3 = 0, $s4 = 0, $s5 = 0, $s6 = 0, $s7 = 0;
        int $t8 = 0, $t9 = 0;
        int $k0 = 0, $k1 = 0;
        int $gp = 0;
        int $sp = 0;
        int $fp = 0;
        int $ra = 0;
        int $hi = 0, $lo = 0;
};

extern RegisterFile reg;

#endif