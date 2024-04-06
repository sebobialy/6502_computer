#include "acia.hpp"

#include <cassert>

ACIA::ACIA( InterruptFunction const& _interruptFunction, ACIAIO& _io )
    : m_interruptFunction( _interruptFunction )
    , m_io( _io )
{
    auto interrupt = [&](unsigned char _c) {
        m_receivedCharacter = _c;

        m_interruptFunction();
    };

    m_io.registerInterrupt( interrupt );
}

void
ACIA::writerRegister( unsigned int _register, unsigned char _value )
{
    assert( _register < 4);

    switch( _register )
    {
        case SIODAT:
        {
            m_io.pushChar( _value );
            return;
        }        
        case SIOSTAT:
        {
            return;
        }        
        case SIOCOM:
        {
            return;
        }        
        case SIOCON:
        {
            return;
        }        
    }
}

unsigned char
ACIA::readRegister( unsigned int _register )
{
    assert( _register < 4);

    switch( _register )
    {
        case SIODAT:
        {
            if ( m_receivedCharacter )
            {
                auto value = *m_receivedCharacter; 
                m_receivedCharacter.reset();
                return value;
            }

            return 0;
        }        
        case SIOSTAT:
        {
            unsigned char status = 0x90;

            if ( m_receivedCharacter )
                status |= 0x08; 

            return status;        }        
        case SIOCOM:
        {
            assert(!"not implemented");
            return 0;
        }        
        case SIOCON:
        {
            assert(!"not implemented");
            return 0;
        }        
    }

    assert(!"unexpected");

    return 0;
}
