MIPS Simulator
==========================

This is a MIPS CPU simulator that accurately executes MIPS-1 big-endian binaries using instructions specified by the MIPS ISA. The list of capabilities is non-exhaustive, but most basic instructions are executable. There is also a rigorous testbench to display the functionality of the simulator. The simulator was primarily coded in C++, while the testbench was developed using ExcelVBA and MIPS. 

Prerequisites
=====================================

When executing testbench, please make sure to have dos2unix installed.
Failing to do so might lead to errors within the testbench.

To install dos2unix, run this in your command line:
```
sudo apt install dos2unix
```

Environment
===========

The target Environment as of project completion is Ubuntu 18.04, with the standard GNU toolchain
installed (i.e. `g++`, `make`), standard command line utilities, and
bash.


Simulator Build and Execution
=============================

The compiler is buildable using the command:
```
make simulator
```
in the root of the respository. This will create a binary called 
```
bin/mips_simulator
```

If any errors occur during build, run:
```
rm bin/mips_simulator
make simulator
```

Testing your own Binaries
=========================

You can customise your own MIPS instruction file and convert it into a .bin file.
To run this file on the simulator:
```
bin/mips_simulator <your_file>.bin
```

Testbench Input/Output
======================

As output, the Testbench prints a CSV file to stdout containing the following fields:
```
TestId , Instruction , Status , Author [, Message]
```

The meaning of the fields is as follows:

- `TestId` : A unique identifier for the particular test.

- `Instruction` : This identifyies the _primary_ instruction being tested.

- `Status` : This will either be `Pass` or `Fail`.
  
- `Author` : The login of the person who created the test.

- `Message` : Optional field for logging/errors.
  
  
Testbench build and executable
==============================

The Testbench is buildable using:
```
make testbench
```
This will create an executable called:
```
bin/mips_testbench
```

Temporary or working files created during execution will be in a directory
called 
```
test/temp
```
Output log files are created in 
```
test/output
```

To run Testbench on its own Simulator:
```
bin/mips_testbench  bin/mips_simulator
```

To run a different Testbench and a different Simulator at the
path 
```
../other-simulator/bin/mips_simulator
```
execute:
```
bin/mips_testbench   ../other-simulator/bin/mips_simulator
```

Memory-Map
----------

```
Offset     |  Length     | Name       | R | W | X |
-----------|-------------|------------|---|---|---|--------------------------------------------------------------------
0x00000000 |        0x4  | ADDR_NULL  |   |   | Y | Jumping to this address means the Binary has finished execution.
0x00000004 |  0xFFFFFFC  | ....       |   |   |   |
0x10000000 |  0x1000000  | ADDR_INSTR | Y |   | Y | Executable memory. The Binary should be loaded here.
0x11000000 |  0xF000000  | ....       |   |   |   |
0x20000000 |  0x4000000  | ADDR_DATA  | Y | Y |   | Read-write data area. Should be zero-initialised.
0x24000000 |  0xC000000  | ....       |   |   |   |
0x30000000 |        0x4  | ADDR_GETC  | Y |   |   | Location of memory mapped input. Read-only.
0x30000004 |        0x4  | ADDR_PUTC  |   | Y |   | Location of memory mapped output. Write-only.
0x30000008 | 0xCFFFFFF8  | ....       |   |   |   |
-----------|-------------|------------|---|---|---|--------------------------------------------------------------------
```


Instructions
------------

Code    |   Meaning                                   
--------|---------------------------------------------
ADD     |  Add (with overflow)
ADDI    |  Add immediate (with overflow)
ADDIU   |  Add immediate unsigned (no overflow)
ADDU    |  Add unsigned (no overflow)
AND     |  Bitwise and
ANDI    |  Bitwise and immediate
BEQ     |  Branch on equal
BGEZ    |  Branch on greater than or equal to zero
BGEZAL  |  Branch on non-negative (>=0) and link
BGTZ    |  Branch on greater than zero
BLEZ    |  Branch on less than or equal to zero
BLTZ    |  Branch on less than zero
BLTZAL  |  Branch on less than zero and link
BNE     |  Branch on not equal
DIV     |  Divide
DIVU    |  Divide unsigned
J       |  Jump
JALR    |  Jump and link register
JAL     |  Jump and link
JR      |  Jump register
LB      |  Load byte
LBU     |  Load byte unsigned
LH      |  Load half-word
LHU     |  Load half-word unsigned
LUI     |  Load upper immediate
LW      |  Load word
LWL     |  Load word left
LWR     |  Load word right
MFHI    |  Move from HI
MFLO    |  Move from LO
MTHI    |  Move to HI
MTLO    |  Move to LO
MULT    |  Multiply
MULTU   |  Multiply unsigned
OR      |  Bitwise or
ORI     |  Bitwise or immediate
SB      |  Store byte
SH      |  Store half-word
SLL     |  Shift left logical
SLLV    |  Shift left logical variable
SLT     |  Set on less than (signed)
SLTI    |  Set on less than immediate (signed)
SLTIU   |  Set on less than immediate unsigned
SLTU    |  Set on less than unsigned
SRA     |  Shift right arithmetic
SRAV    |  Shift right arithmetic
SRL     |  Shift right logical
SRLV    |  Shift right logical variable
SUB     |  Subtract
SUBU    |  Subtract unsigned
SW      |  Store word
XOR     |  Bitwise exclusive or
XORI    |  Bitwise exclusive or immediate
