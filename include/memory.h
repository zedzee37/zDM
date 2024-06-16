#include <stdint.h>

extern uint16_t pc;
extern uint8_t memory[0xFFFF];

extern int load_rom(char *s);
extern uint8_t read8(uint16_t p);
extern uint16_t read16(uint16_t p);
extern void write8(uint16_t address, uint8_t v);
extern uint8_t msb(uint16_t v);
extern uint8_t lsb(uint8_t v);
extern uint16_t u16(uint8_t lsb, uint8_t msb);
