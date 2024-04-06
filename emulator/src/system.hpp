#pragma once

#include "acia.hpp"
#include "cpu/mos6502.h"

class ACIAIO;

class System
{
public:
    System( ACIAIO& _io );   

    uint8_t busRead( uint16_t _address );

    void busWrite( uint16_t _address, uint8_t _data );

    void interrupt();

    void moveForward();

private:
    uint8_t ramRead( uint16_t _address );

    void ramWrite( uint16_t _address, uint8_t _data );

    uint8_t romRead( uint16_t _address );

    void romWrite( uint16_t _address, uint8_t _data );

    uint8_t ioRead( uint16_t _address );

    void ioWrite( uint16_t _address, uint8_t _data );

private:
    ACIAIO& m_io;

    ACIA m_acia;

    mos6502 m_cpu;

    static constexpr int ramSize = 0x8000;

    uint8_t ram[ramSize];
};
