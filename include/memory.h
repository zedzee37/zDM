#include <stdint.h>

union Memory {
    uint8_t program[0x3fff];
    uint8_t cartridge_bank[0x3fff];
    uint8_t vram[0x1fff];
    uint8_t external_ram[0x1fff];
    uint8_t work_ram[0x0fff];
    uint8_t echo_ram[0x1dff];
    uint8_t oam[0x009f];
    uint8_t not_usable[0x005f];
    uint8_t io[0x007f];
    uint8_t hram[0xff7e];
    uint8_t ie;
    uint8_t memory[0xffff];
};

extern uint8_t read(union Memory *mem, uint16_t address);
extern void write8(union Memory *mem, uint16_t address, uint8_t v);
extern int read_rom(union Memory *mem, char *fp);

