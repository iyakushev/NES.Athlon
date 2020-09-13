//
// Created by IY on 9/1/20.
//

#include "Athlon6502.h"
Athlon6502::Athlon6502() {}
Athlon6502::~Athlon6502() {}

uint8_t Athlon6502::fetchData(uint16_t addr) {
    return bus->read(addr);
}

void Athlon6502::sendData(uint16_t addr, uint8_t data) {
    bus->write(addr, data);
}