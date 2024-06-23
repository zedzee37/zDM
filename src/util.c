#include "util.h"
#include <stdio.h>

uint8_t util_msb(uint16_t v) {
    return v >> 8; 
}

uint8_t util_lsb(uint16_t v) {
    return v;
}

uint16_t util_u16(uint8_t lsb, uint8_t msb) {
    return (msb << 8) | lsb;
}

void util_log(enum LogLevel level, char *message, ...) {
    va_list args;
    va_start(args, message);

    // Print the log level
    switch (level) {
        case INFO:
            printf("\x1b[34m[INFO] ");
            break;
        case DEBUG:
            printf("\x1b[33m[DEBUG] ");
            break;
        case ERROR:
            printf("\x1b[31m[ERROR] ");
            break;
        case WARNING:
            printf("\x1b[33m[WARNING] ");
        default:
            printf("[UNKNOWN] ");
    }

    // Print the message and any additional arguments
    printf("\x1b[37m"); 
    vprintf(message, args);
    printf("\n");

    va_end(args);
}

