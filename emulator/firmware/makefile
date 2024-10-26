clean:
	rm -f symon.asm
	rm -f symon.bin
	rm -f symon.o

all: 
	./_run_64tass.sh
	objcopy -I binary symon.bin -O elf64-x86-64 symon.o