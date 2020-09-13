//
// Created by IY on 9/1/20.
//

#ifndef C_NES_BUS_H
#define C_NES_BUS_H

#include <cstdint>
#include "Athlon6502.h"
#include <array>


class Bus {
public:
    Bus();
    ~Bus();

    Athlon6502 CPU;
    std::array<uint8_t, 64*1024> RAM;

    void write(uint16_t addr, uint8_t data);
    uint8_t read(uint16_t addr);
};


#endif //C_NES_BUS_H
