#pragma once

#include "acia.hpp"

class IOConsole : public ACIAIO
{
public:
    IOConsole();

    ~IOConsole();

    void registerInterrupt( InterruptFunction const& _interrupt ) override;

    void pushChar( unsigned char _c ) override;

    void checkInput();

private:
    InterruptFunction m_interrupt;
};
