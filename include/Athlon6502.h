//
// Created by IY on 9/1/20.
//

#ifndef C_NES_ATHLON6502_H
#define C_NES_ATHLON6502_H

#include "Bus.h"

class Athlon6502 {
private:
    Bus* bus = nullptr;
    void sendData(uint16_t addr, uint8_t data);
    uint8_t fetchData(uint16_t addr);
    uint8_t fetchInstructionData();
    uint8_t instruction_data      = 0x00;
    uint8_t instruction_cycles    = 0;
    uint8_t instruction_oppcode   = 0x00;
    uint16_t instruction_abs_addr = 0x0000;
    uint16_t instruction_rel_addr = 0x0000;


    void setFlag(Flags f);
    uint8_t getFlag(Flags f);

    // REGISTERS
    uint8_t x  = 0x00; // The X register is an 8-bit register typically used as a counter or an offset for certain addressing modes
    uint8_t y  = 0x00; // The Y register is an 8-bit register which is used in the same way as the X register, as a counter or to store an offset. Unlike the X register, the Y register cannot affect the stack pointer.
    uint8_t a  = 0x00; // The accumulator is an 8-bit register which stores the results of arithmetic and logic operations
    uint8_t sp = 0x00; // The stack pointer is an 8-bit register which serves as an offset from $0100
    uint8_t pc = 0x00; // The program counter is a 16-bit register which holds the address of the next instruction to be executed
    uint8_t ps = 0x00; // The status register contains a number of single bit flags which are set or cleared when instructions are executed.



public:
    Athlon6502();
    ~Athlon6502();
    void connectBus(Bus* bus) {this->bus = bus;}
    void reset(); // Resets everything in the CPU
    void interrupt(); // Executes requested interrupt
    void nonMaskableInterrupt(); // Executes requested interrupt that can't be disabled
    void clock(); // Consumes one clock cycle
    // FLAGS
    enum Flags {
        C = 1 << 0; // Carry
        Z = 1 << 1; // Zero
        I = 1 << 2; // Interrupt disable
        D = 1 << 3; // Decimal mode
        B = 1 << 4; // Break
        X = 1 << 5; // Unused flag. Does nothing
        V = 1 << 6; // Overflow
        N = 1 << 7; // Negative
    };
};


#endif //C_NES_ATHLON6502_H
