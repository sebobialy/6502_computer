#pragma once

#include <functional>
#include <optional>

class ACIAIO
{
public:
    using InterruptFunction = std::function< void(unsigned char) >;

public:
    virtual void registerInterrupt( InterruptFunction const& _interrupt ) = 0;

    virtual void pushChar( unsigned char _c ) = 0;
};

class ACIA
{
public:
    using InterruptFunction = std::function< void(void) >;

public:
    ACIA( InterruptFunction const& _interruptFunction, ACIAIO& _io );

    void writerRegister( unsigned int _register, unsigned char _value );

    unsigned char readRegister( unsigned int _register );

private:
    enum Registers {
        SIODAT=0,SIOSTAT=1,SIOCOM=2,SIOCON=3
    };

private:
    InterruptFunction m_interruptFunction;

    ACIAIO& m_io;

    std::optional< unsigned char > m_receivedCharacter;
};
