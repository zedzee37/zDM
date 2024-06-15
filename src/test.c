#include "cpu.h"
#include "zdm.h"
#include "memory.h"

void debug(int argc, char **argv) {
    load_rom(argv[1]);
    pc = 0;
    for (int i = 0; i < 1000; i++) {
        execute();
    }
}
