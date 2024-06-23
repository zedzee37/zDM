#include "debugger.h"
#include "cpu.h"
#include "registers.h"
#include "memory.h"
#include "util.h"
#include <stdio.h>

void enter_debug_mode(struct Debugger *dbgr) {
    util_log(DEBUG, "Entered Debug Mode, type 'q' to exit.");
    util_log(DEBUG, "   Type 's' to step.");
    util_log(DEBUG, "   Type 'm' to print a region of memory");
    util_log(DEBUG, "   Type 'i' to toggle instruction logging");
    util_log(DEBUG, "   Type 'r' to print the contents of the registers.");

    int in_debug_mode = 1;
    while (in_debug_mode) {
        switch (getchar()) {
            case STEP:
                step(dbgr);
                break;
            case REGION:
                util_log(DEBUG, "What memory location would you like to print from?");
                unsigned int *from;
                scanf("%x", from);

                util_log(DEBUG, "What memory location would you like to print to?");
                unsigned int *to;
                scanf("%x", to);

                print_region(dbgr->cpu->mem->memory, *from, *to);
                break;
            case INSTRUCTION_LOGGING:
                dbgr->cpu->instruction_logging = true;
                break;
            case REGISTERS:
                print_registers(dbgr->cpu->registers);
                break;
            case QUIT:
                in_debug_mode = 0;
                break;
            default:
                break;
        }
    }
    util_log(DEBUG, "Exiting debug mode.");
}

void step(struct Debugger *dbgr) {
    execute(dbgr->cpu);
}
