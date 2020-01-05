#ifndef PROGRAMCOUNTER_HPP
#define PROGRAMCOUNTER_HPP

class programCounter{
    public:
        void increment();
        unsigned int ProgCount;
        bool delayslot = 0;
};

extern programCounter PC;

#endif