#include "cpu/mos6502.h"

#include "console.hpp"
#include "acia.hpp"
#include "system.hpp"

#include <cassert>

// void interrupt(void)
// {
// }

// IOConsole console;
// ACIA acia( interrupt, console );

// const int ramSize = 0x8000;
// const int ioSize = 8;
// extern "C" uint8_t _binary_firmware_SYMONIII_OBJ_start[8*1024];

// uint8_t ram[ramSize];

// uint8_t ramRead( uint16_t _address )
// {
//     assert( _address < ramSize );

//     return ram[_address];
// }

// void ramWrite( uint16_t _address, uint8_t _data )
// {
//     assert( _address < ramSize );

//     ram[_address]=_data;
// }

// uint8_t romRead( uint16_t _address )
// {
//     return _binary_firmware_SYMONIII_OBJ_start[ _address ];
// }





// // command

// // control
// enum class ClockSource {
//       External
//     , Internal
// };

// enum class DataWordLenght {
//       WordLenght8
//     , WordLenght7
//     , WordLenght6
//     , WordLenght5
// };

// enum class StopBits {
//       OneStopBit
//     , TwoStopBits
// };

// uint8_t baudRate = 0;
// ClockSource clockSource = ClockSource::External;
// DataWordLenght dataWordLenght = DataWordLenght::WordLenght8;
// StopBits stopBits = StopBits::OneStopBit;

// void ioWrite( uint16_t _address, uint8_t _data )
// {
//     acia.writerRegister( _address, _data );

//     // if ( _address == 0 )
//     // {
//     //     printf( "%c", _data );
//     // }
//     // else if ( _address == 2 )
//     // {
//     // }
//     // else if ( _address = 3 )
//     // {
//     //     baudRate = _data & 0x0f;
//     //     clockSource = ( _data & 0x10 ) != 0 ? ClockSource::Internal : ClockSource::External;
//     //     uint8_t wordSize = ( _data & 0x60 ) >> 5;
//     //     switch (wordSize )
//     //     {
//     //         case 0:
//     //             dataWordLenght = DataWordLenght::WordLenght8;
//     //             break;
//     //         case 1:
//     //             dataWordLenght = DataWordLenght::WordLenght7;
//     //             break;
//     //         case 2:
//     //             dataWordLenght = DataWordLenght::WordLenght6;
//     //             break;
//     //         case 3:
//     //             dataWordLenght = DataWordLenght::WordLenght5;
//     //             break;
//     //     }
//     //     stopBits = ( _data & 0x80 ) != 0 ? StopBits::TwoStopBits : StopBits::OneStopBit;
//     // }
// }

// uint8_t ioRead( uint16_t _address )
// {
//     return acia.readRegister( _address );
// }

// uint8_t busRead( uint16_t _address )
// {
//     if ( _address < ramSize )
//         return ramRead( _address );
//     if ( _address >=0x8000 && _address <0x8000+ioSize )
//         return ioRead( _address - 0x8000 );
//     else
//         return romRead( _address - 0xe000 );
// }

// void busWrite( uint16_t _address, uint8_t _data )
// {
//     if ( _address < ramSize )
//     {
//         ramWrite( _address, _data );
//         return;
//     }
//     if ( _address >=0x8000 && _address <0x8000+ioSize )
//     {
//         ioWrite( _address - 0x8000, _data );
//         return;
//     }

//     assert( !"illegal address" );
// }

int main()
{
    // mos6502 cpu( busRead, busWrite );

    // cpu.Reset();

    // uint64_t unused;

    // while( true )
    // {
    //     cpu.Run( 100, unused );
    //     console.checkInput();
    // }

    IOConsole console;

    System system(console);

    while(true)
    {
        system.moveForward();
        console.checkInput();
    }
}
