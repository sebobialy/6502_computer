#include "system.hpp"

#include <cassert>

extern "C" uint8_t _binary_symon_bin_start[8*1024];

System* global = 0;

uint8_t busReadGlobal( uint16_t _address )
{
    return global->busRead( _address );
}

void busWriteGlobal( uint16_t _address, uint8_t _data )
{
    global->busWrite( _address, _data );
}

System::System( ACIAIO& _io )
    : m_io( _io )
    , m_acia( std::bind(&System::interrupt,this), _io )
    , m_cpu( busReadGlobal, busWriteGlobal )
{
    global = this;
    m_cpu.Reset();
}

uint8_t
System::busRead( uint16_t _address )
{
    if ( _address < ramSize )
        return ramRead( _address );
    if ( _address >=0x8000 && _address <0x8004 )
        return ioRead( _address - 0x8000 );
    else
        return romRead( _address - 0xe000 );
}

void
System::busWrite( uint16_t _address, uint8_t _data )
{
        if ( _address < ramSize )
    {
        ramWrite( _address, _data );
        return;
    }
    if ( _address >=0x8000 && _address <0x8004 )
    {
        ioWrite( _address - 0x8000, _data );
        return;
    }

    assert( !"illegal address" );
}


uint8_t
System::ramRead( uint16_t _address )
{
    assert( _address < ramSize );

    return ram[_address];
}

void
System::ramWrite( uint16_t _address, uint8_t _data )
{
    assert( _address < ramSize );

    ram[_address]=_data;
}

uint8_t
System::romRead( uint16_t _address )
{
    return _binary_symon_bin_start[ _address ];
}

void
System::romWrite( uint16_t _address, uint8_t _data )
{
    assert(!"impossible");
}

uint8_t
System::ioRead( uint16_t _address )
{
    return m_acia.readRegister( _address );
}

void
System::ioWrite( uint16_t _address, uint8_t _data )
{
    m_acia.writerRegister( _address, _data );
}

void
System::interrupt()
{
    m_cpu.IRQ();
}

void
System::moveForward()
{
    uint64_t unused;
    m_cpu.Run( 100, unused );
}
