#include <stdint.h>

enum DebugCommands {
    STEP = 's',
    REGION = 'm',
    INSTRUCTION_LOGGING = 'i',
    REGISTERS = 'r',
    QUIT = 'q'
};

struct Debugger {
    int step;
    struct Cpu *cpu;
};

extern void enter_debug_mode(struct Debugger *dbgr);
extern void step(struct Debugger *dbgr);
