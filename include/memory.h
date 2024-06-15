#include <stdint.h>

extern uint16_t pc;
extern uint8_t memory[0xFFFF];

extern int load_rom(char *s);
extern uint8_t read8(uint16_t p);
extern uint16_t read16(uint16_t p);
extern void write8(uint16_t address, uint8_t v);
