#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif
#include <string>

#include "include/memory.hpp"
#include "include/simulator.hpp"
#include "include/RegisterFile.hpp"
#include "include/ProgramCounter.hpp"
using namespace std;

RegisterFile reg;
programCounter PC;
RAM r;
simulator S;

int main(int argc, char** argv){
    fstream file;
    unsigned char n;

    try{
        if(argc < 2){
            file.open("bin/test/temp.bin", ios::in | ios::binary);
        }

        else{
            file.open(argv[1], ios::in | ios::binary);
        }

        if(!file.is_open()){
            throw "Error opening binary file!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-20);
    }

    file.seekg(0, file.end);
    int binlen = file.tellg();
    file.seekg(0, file.beg);

    for(int i=0; i<binlen; i++){
        try{
            file.read((char *) (&n), sizeof(n));

            if(!file){
                throw "Error reading binary file!";
            }
        } catch(const char* msg){
            cerr << msg << endl;
            exit(-20);
        }

        r.loadtoMemory(n);
    }

    file.close();

    S.execute();
    return (reg.readRegister(2) & 0xFF);
}