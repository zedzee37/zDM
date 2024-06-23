#include <stdint.h>

struct Debugger {
    int step;
    struct Cpu *cpu;
};

extern void enter_debug_mode(struct Debugger *dbgr);
extern void exit_debug_mode(struct Debugger *dbgr);
extern void step(struct Debugger *dbgr);
