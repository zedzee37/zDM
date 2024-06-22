D_CC = clang
CC = gcc
SRC = src/*.c
BIN = gameboy
D_BIN = debug_gameboy
ROM = totally_not_stolen_rom
INCLUDE = include

release:
	${CC} ${SRC} -lSDL2 -I${INCLUDE} -o ${BIN}.o -O3 

debug:
	${D_CC} ${SRC} -g -lSDL2 -I${INCLUDE} -o ${D_BIN}.o -DDEBUGF=1

run:
	make release
	./${BIN}.o ${ROM}.gb

run_debug:
	make debug
	./${D_BIN}.o ${ROM}.gb

