#include "console.hpp"

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <termios.h>

IOConsole::IOConsole()
{
    fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
    setvbuf( stdin, NULL, _IONBF, 0 );

    struct termios term;
    tcgetattr( fileno(stdin), &term );
    term.c_lflag &= ~ICANON;
    tcsetattr( fileno(stdin), TCSANOW, &term);
}

IOConsole::~IOConsole()
{
    struct termios term;
    tcgetattr( fileno(stdin), &term );
    term.c_lflag |= ICANON;
    tcsetattr( fileno(stdin), TCSANOW, &term);
}

void
IOConsole::registerInterrupt( InterruptFunction const& _interrupt )
{
    m_interrupt =_interrupt;
}

void
IOConsole::pushChar( unsigned char _c )
{
    printf( "%c", _c );
}

void
IOConsole::checkInput()
{
    unsigned char buf[1];

    int numRead = read(0, buf, 1);
    if (numRead < 1 )
        return;

    auto value = buf[0];

    if ( value == 10 )
        value = 13;

    m_interrupt( value );
}
