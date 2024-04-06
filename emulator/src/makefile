CC=gcc
CPP=g++
CFLAGS=-g -O0 -I .

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp
	$(CPP) -c -o $@ $< $(CFLAGS)

%.o: %.OBJ
	ld -r -b binary -o $@ $<


emulator: main.o cpu/mos6502.o firmware/SYMONIII.o acia.o console.o system.o
	$(CPP) -o emulator main.o cpu/mos6502.o firmware/SYMONIII.o acia.o console.o system.o

clean:
	rm *.o
	rm emulator

all: clean emulator