#include <stdint.h>

struct Cpu {
    union Memory *mem;
    struct Registers *registers;
};

extern char *instructions[256];

extern void execute(struct Cpu *cpu);
extern void execute_instruction(struct Cpu *cpu, uint8_t instruction);
