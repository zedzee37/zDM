#include <stdio.h>
#include "memory.h"
#include "util.h"

uint8_t read(union Memory *mem, uint16_t address) {
    return mem->memory[address];    
}

void write8(union Memory *mem, uint16_t address, uint8_t v) {
    mem->memory[address] = v;
}

int read_rom(union Memory *mem, char *file_path) {
    FILE *fp = fopen(file_path, "rb");
    
    if (fp == NULL) {
        util_log(ERROR, "Could not read from file: %s", file_path);
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    fread(mem->program, 0x3fff, sizeof(uint8_t), fp);
    fclose(fp);

    return 1;
}
