#include "registers.h"
#include "util.h"


void print_registers(struct Registers *registers) {
    util_log(DEBUG, "\x1b[32mRegisters Contents:");
    PRINT_REGISTER_INFO(af, "af");
    PRINT_REGISTER_INFO(bc, "bc");
    PRINT_REGISTER_INFO(de, "de");
    PRINT_REGISTER_INFO(hl, "hl");
    
    util_log(DEBUG, "    Program Counter: %d", registers->pc);
    util_log(DEBUG, "    Stack Pointer: %d", registers->sp);
}
