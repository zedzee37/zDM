#include <stdint.h>
#include <stdarg.h>

enum LogLevel {
    INFO, WARNING, DEBUG, ERROR
};

extern uint8_t util_msb(uint16_t v);
extern uint8_t util_lsb(uint16_t v);
extern uint16_t util_u16(uint8_t lsb, uint8_t msb);
extern void util_log(enum LogLevel level, char *message, ...);
