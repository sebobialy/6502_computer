#include "cpu/mos6502.h"

#include "console.hpp"
#include "acia.hpp"
#include "system.hpp"

#include <cassert>

int main()
{
    IOConsole console;

    System system(console);

    while(true)
    {
        system.moveForward();
        console.checkInput();
    }
}
