#include "memory.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

uint16_t pc;
uint8_t memory[0xFFFF];

int load_rom(char *rom) {
	FILE *fp = fopen(rom, "rb");

	if (fp == NULL) {
		return false;
	}

	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	fread(memory, sizeof(uint8_t), size, fp);

	fclose(fp);
	return true;
}

uint8_t read8(uint16_t p) {
    return memory[p];
}

uint16_t read16(uint16_t p) {
    return u16(memory[p], memory[p + 1]);
}

void write8(uint16_t address, uint8_t v) {
    memory[address] = v;
}

uint8_t msb(uint16_t v) {
    return v >> 8;
}

uint8_t lsb(uint8_t v) {
    return v & 0xFF;
}

uint16_t u16(uint8_t lsb, uint8_t msb) {
    return (msb << 8) | lsb;
}
