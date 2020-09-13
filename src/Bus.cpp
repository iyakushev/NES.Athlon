//
// Created by IY on 9/1/20.
//

#include "Bus.h"

Bus::Bus() {
    for(auto &i:RAM) i = 0x0; // fill with zeroes.
    CPU.connectBus(this);
}

Bus::~Bus() {}

void Bus::write(uint16_t addr, uint8_t data) {
    RAM[addr] = data;
}

uint8_t Bus::read(uint16_t addr) {
    return RAM[addr];
}