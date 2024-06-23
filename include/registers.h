#include <stdint.h>

#define FLAG_ZERO (1 << 7)
#define FLAG_NEGATIVE (1 << 6)
#define FLAG_HALFCARRY (1 << 5)
#define FLAG_CARRY (1 << 4)

#define IS_FLAG(f, fl) ((f) & (fl) != 0)
#define ENABLE_FLAG(f, fl) f |= fl
#define DISABLE_FLAG(f, fl) f &= ~fl

#define PRINT_REGISTER_INFO(r, s) util_log(DEBUG, "    Register: %s, contents: [h: %x, n: %d]", s, registers->r, registers->r)

struct Registers {
    struct {
        union {
            struct {
                uint8_t f;
                uint8_t a;
            };
            uint16_t af;
        };
    };
    struct {
        union {
            struct {
                uint8_t b;
                uint8_t c;
            };
            uint16_t bc;
        };
    };
    struct {
        union {
            struct {
                uint8_t d;
                uint8_t e;
            };
            uint16_t de;
        };
    };
    struct {
        union {
            struct {
                uint8_t h;
                uint8_t l;
            };
            uint16_t hl;
        };
    };
    uint16_t pc;
    uint16_t sp;
};

extern void print_registers(struct Registers *rgsters);
