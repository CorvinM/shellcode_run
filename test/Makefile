ASM_FILES = $(wildcard *.asm)
BIN_FILES = $(ASM_FILES:.asm=.bin)
OUTPUTS = $(BIN_FILES)

.PHONY: all clean

all: $(OUTPUTS)

clean:
	rm -rf $(OUTPUTS)

%.bin: %.asm
	nasm -f bin -o $@ $^