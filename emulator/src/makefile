CC=gcc
CPP=g++
CFLAGS=-g -O0 -I .

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp
	$(CPP) -c -o $@ $< $(CFLAGS)

%.o: %.OBJ
	ld -r -b binary -o $@ $<

emulator: main.o cpu/mos6502.o acia.o console.o system.o
	$(CPP) -o emulator main.o cpu/mos6502.o ../firmware/symon.o acia.o console.o system.o

clean:
	rm -f *.o
	rm -f cpu/*.o
	rm -f emulator

all: emulator
