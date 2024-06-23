#include "cpu.h"
#include "memory.h"
#include "registers.h"

void execute(struct Cpu *cpu) {
    uint8_t instruction = read(cpu->mem, cpu->registers->pc);
    cpu->registers->pc++;
    execute_instruction(cpu, instruction);
}

void execute_instruction(struct Cpu *cpu, uint8_t instruction) {
    char *op = instructions[instruction];

    switch (instruction) {
        case 0x00:    // NOP
            break;
        case 0x01:    // LD BC d16
            break;
        case 0x02:    // LD (BC) A
            break;
        case 0x03:    // INC BC
            break;
        case 0x04:    // INC B
            break;
        case 0x05:    // DEC B
            break;
        case 0x06:    // LD B d8
            break;
        case 0x07:    // RLCA
            break;
        case 0x08:    // LD (a16) SP
            break;
        case 0x09:    // ADD HL BC
            break;
        case 0x0a:    // LD A (BC)
            break;
        case 0x0b:    // DEC BC
            break;
        case 0x0c:    // INC C
            break;
        case 0x0d:    // DEC C
            break;
        case 0x0e:    // LD C d8
            break;
        case 0x0f:    // RRCA
            break;
        case 0x10:    // STOP 0
            break;
        case 0x11:    // LD DE d16
            break;
        case 0x12:    // LD (DE) A
            break;
        case 0x13:    // INC DE
            break;
        case 0x14:    // INC D
            break;
        case 0x15:    // DEC D
            break;
        case 0x16:    // LD D d8
            break;
        case 0x17:    // RLA
            break;
        case 0x18:    // JR r8
            break;
        case 0x19:    // ADD HL DE
            break;
        case 0x1a:    // LD A (DE)
            break;
        case 0x1b:    // DEC DE
            break;
        case 0x1c:    // INC E
            break;
        case 0x1d:    // DEC E
            break;
        case 0x1e:    // LD E d8
            break;
        case 0x1f:    // RRA
            break;
        case 0x20:    // JR NZ r8
            break;
        case 0x21:    // LD HL d16
            break;
        case 0x22:    // LD (HL+) A
            break;
        case 0x23:    // INC HL
            break;
        case 0x24:    // INC H
            break;
        case 0x25:    // DEC H
            break;
        case 0x26:    // LD H d8
            break;
        case 0x27:    // DAA
            break;
        case 0x28:    // JR Z r8
            break;
        case 0x29:    // ADD HL HL
            break;
        case 0x2a:    // LD A (HL+)
            break;
        case 0x2b:    // DEC HL
            break;
        case 0x2c:    // INC L
            break;
        case 0x2d:    // DEC L
            break;
        case 0x2e:    // LD L d8
            break;
        case 0x2f:    // CPL
            break;
        case 0x30:    // JR NC r8
            break;
        case 0x31:    // LD SP d16
            break;
        case 0x32:    // LD (HL-) A
            break;
        case 0x33:    // INC SP
            break;
        case 0x34:    // INC (HL)
            break;
        case 0x35:    // DEC (HL)
            break;
        case 0x36:    // LD (HL) d8
            break;
        case 0x37:    // SCF
            break;
        case 0x38:    // JR C r8
            break;
        case 0x39:    // ADD HL SP
            break;
        case 0x3a:    // LD A (HL-)
            break;
        case 0x3b:    // DEC SP
            break;
        case 0x3c:    // INC A
            break;
        case 0x3d:    // DEC A
            break;
        case 0x3e:    // LD A d8
            break;
        case 0x3f:    // CCF
            break;
        case 0x40:    // LD B B
            break;
        case 0x41:    // LD B C
            break;
        case 0x42:    // LD B D
            break;
        case 0x43:    // LD B E
            break;
        case 0x44:    // LD B H
            break;
        case 0x45:    // LD B L
            break;
        case 0x46:    // LD B (HL)
            break;
        case 0x47:    // LD B A
            break;
        case 0x48:    // LD C B
            break;
        case 0x49:    // LD C C
            break;
        case 0x4a:    // LD C D
            break;
        case 0x4b:    // LD C E
            break;
        case 0x4c:    // LD C H
            break;
        case 0x4d:    // LD C L
            break;
        case 0x4e:    // LD C (HL)
            break;
        case 0x4f:    // LD C A
            break;
        case 0x50:    // LD D B
            break;
        case 0x51:    // LD D C
            break;
        case 0x52:    // LD D D
            break;
        case 0x53:    // LD D E
            break;
        case 0x54:    // LD D H
            break;
        case 0x55:    // LD D L
            break;
        case 0x56:    // LD D (HL)
            break;
        case 0x57:    // LD D A
            break;
        case 0x58:    // LD E B
            break;
        case 0x59:    // LD E C
            break;
        case 0x5a:    // LD E D
            break;
        case 0x5b:    // LD E E
            break;
        case 0x5c:    // LD E H
            break;
        case 0x5d:    // LD E L
            break;
        case 0x5e:    // LD E (HL)
            break;
        case 0x5f:    // LD E A
            break;
        case 0x60:    // LD H B
            break;
        case 0x61:    // LD H C
            break;
        case 0x62:    // LD H D
            break;
        case 0x63:    // LD H E
            break;
        case 0x64:    // LD H H
            break;
        case 0x65:    // LD H L
            break;
        case 0x66:    // LD H (HL)
            break;
        case 0x67:    // LD H A
            break;
        case 0x68:    // LD L B
            break;
        case 0x69:    // LD L C
            break;
        case 0x6a:    // LD L D
            break;
        case 0x6b:    // LD L E
            break;
        case 0x6c:    // LD L H
            break;
        case 0x6d:    // LD L L
            break;
        case 0x6e:    // LD L (HL)
            break;
        case 0x6f:    // LD L A
            break;
        case 0x70:    // LD (HL) B
            break;
        case 0x71:    // LD (HL) C
            break;
        case 0x72:    // LD (HL) D
            break;
        case 0x73:    // LD (HL) E
            break;
        case 0x74:    // LD (HL) H
            break;
        case 0x75:    // LD (HL) L
            break;
        case 0x76:    // HALT
            break;
        case 0x77:    // LD (HL) A
            break;
        case 0x78:    // LD A B
            break;
        case 0x79:    // LD A C
            break;
        case 0x7a:    // LD A D
            break;
        case 0x7b:    // LD A E
            break;
        case 0x7c:    // LD A H
            break;
        case 0x7d:    // LD A L
            break;
        case 0x7e:    // LD A (HL)
            break;
        case 0x7f:    // LD A A
            break;
        case 0x80:    // ADD A B
            break;
        case 0x81:    // ADD A C
            break;
        case 0x82:    // ADD A D
            break;
        case 0x83:    // ADD A E
            break;
        case 0x84:    // ADD A H
            break;
        case 0x85:    // ADD A L
            break;
        case 0x86:    // ADD A (HL)
            break;
        case 0x87:    // ADD A A
            break;
        case 0x88:    // ADC A B
            break;
        case 0x89:    // ADC A C
            break;
        case 0x8a:    // ADC A D
            break;
        case 0x8b:    // ADC A E
            break;
        case 0x8c:    // ADC A H
            break;
        case 0x8d:    // ADC A L
            break;
        case 0x8e:    // ADC A (HL)
            break;
        case 0x8f:    // ADC A A
            break;
        case 0x90:    // SUB B
            break;
        case 0x91:    // SUB C
            break;
        case 0x92:    // SUB D
            break;
        case 0x93:    // SUB E
            break;
        case 0x94:    // SUB H
            break;
        case 0x95:    // SUB L
            break;
        case 0x96:    // SUB (HL)
            break;
        case 0x97:    // SUB A
            break;
        case 0x98:    // SBC A B
            break;
        case 0x99:    // SBC A C
            break;
        case 0x9a:    // SBC A D
            break;
        case 0x9b:    // SBC A E
            break;
        case 0x9c:    // SBC A H
            break;
        case 0x9d:    // SBC A L
            break;
        case 0x9e:    // SBC A (HL)
            break;
        case 0x9f:    // SBC A A
            break;
        case 0xa0:    // AND B
            break;
        case 0xa1:    // AND C
            break;
        case 0xa2:    // AND D
            break;
        case 0xa3:    // AND E
            break;
        case 0xa4:    // AND H
            break;
        case 0xa5:    // AND L
            break;
        case 0xa6:    // AND (HL)
            break;
        case 0xa7:    // AND A
            break;
        case 0xa8:    // XOR B
            break;
        case 0xa9:    // XOR C
            break;
        case 0xaa:    // XOR D
            break;
        case 0xab:    // XOR E
            break;
        case 0xac:    // XOR H
            break;
        case 0xad:    // XOR L
            break;
        case 0xae:    // XOR (HL)
            break;
        case 0xaf:    // XOR A
            break;
        case 0xb0:    // OR B
            break;
        case 0xb1:    // OR C
            break;
        case 0xb2:    // OR D
            break;
        case 0xb3:    // OR E
            break;
        case 0xb4:    // OR H
            break;
        case 0xb5:    // OR L
            break;
        case 0xb6:    // OR (HL)
            break;
        case 0xb7:    // OR A
            break;
        case 0xb8:    // CP B
            break;
        case 0xb9:    // CP C
            break;
        case 0xba:    // CP D
            break;
        case 0xbb:    // CP E
            break;
        case 0xbc:    // CP H
            break;
        case 0xbd:    // CP L
            break;
        case 0xbe:    // CP (HL)
            break;
        case 0xbf:    // CP A
            break;
        case 0xc0:    // RET NZ
            break;
        case 0xc1:    // POP BC
            break;
        case 0xc2:    // JP NZ a16
            break;
        case 0xc3:    // JP a16
            break;
        case 0xc4:    // CALL NZ a16
            break;
        case 0xc5:    // PUSH BC
            break;
        case 0xc6:    // ADD A d8
            break;
        case 0xc7:    // RST 00H
            break;
        case 0xc8:    // RET Z
            break;
        case 0xc9:    // RET
            break;
        case 0xca:    // JP Z a16
            break;
        case 0xcb:    // PREFIX CB
            break;
        case 0xcc:    // CALL Z a16
            break;
        case 0xcd:    // CALL a16
            break;
        case 0xce:    // ADC A d8
            break;
        case 0xcf:    // RST 08H
            break;
        case 0xd0:    // RET NC
            break;
        case 0xd1:    // POP DE
            break;
        case 0xd2:    // JP NC a16
            break;
        case 0xd4:    // CALL NC a16
            break;
        case 0xd5:    // PUSH DE
            break;
        case 0xd6:    // SUB d8
            break;
        case 0xd7:    // RST 10H
            break;
        case 0xd8:    // RET C
            break;
        case 0xd9:    // RETI
            break;
        case 0xda:    // JP C a16
            break;
        case 0xdc:    // CALL C a16
            break;
        case 0xde:    // SBC A d8
            break;
        case 0xdf:    // RST 18H
            break;
        case 0xe0:    // LDH (a8) A
            break;
        case 0xe1:    // POP HL
            break;
        case 0xe2:    // LD (C) A
            break;
        case 0xe5:    // PUSH HL
            break;
        case 0xe6:    // AND d8
            break;
        case 0xe7:    // RST 20H
            break;
        case 0xe8:    // ADD SP r8
            break;
        case 0xe9:    // JP (HL)
            break;
        case 0xea:    // LD (a16) A
            break;
        case 0xee:    // XOR d8
            break;
        case 0xef:    // RST 28H
            break;
        case 0xf0:    // LDH A (a8)
            break;
        case 0xf1:    // POP AF
            break;
        case 0xf2:    // LD A (C)
            break;
        case 0xf3:    // DI
            break;
        case 0xf5:    // PUSH AF
            break;
        case 0xf6:    // OR d8
            break;
        case 0xf7:    // RST 30H
            break;
        case 0xf8:    // LD HL SP+r8
            break;
        case 0xf9:    // LD SP HL
            break;
        case 0xfa:    // LD A (a16)
            break;
        case 0xfb:    // EI
            break;
        case 0xfe:    // CP d8
            break;
        case 0xff:    // RST 38H
            break;
        default:
            break;
    }
}

char *instructions[256] = {
    "NOP",
    "LD BC d16",
    "LD (BC) A",
    "INC BC",
    "INC B",
    "DEC B",
    "LD B d8",
    "RLCA",
    "LD (a16) SP",
    "ADD HL BC",
    "LD A (BC)",
    "DEC BC",
    "INC C",
    "DEC C",
    "LD C d8",
    "RRCA",
    "STOP 0",
    "LD DE d16",
    "LD (DE) A",
    "INC DE",
    "INC D",
    "DEC D",
    "LD D d8",
    "RLA",
    "JR r8",
    "ADD HL DE",
    "LD A (DE)",
    "DEC DE",
    "INC E",
    "DEC E",
    "LD E d8",
    "RRA",
    "JR NZ r8",
    "LD HL d16",
    "LD (HL+) A",
    "INC HL",
    "INC H",
    "DEC H",
    "LD H d8",
    "DAA",
    "JR Z r8",
    "ADD HL HL",
    "LD A (HL+)",
    "DEC HL",
    "INC L",
    "DEC L",
    "LD L d8",
    "CPL",
    "JR NC r8",
    "LD SP d16",
    "LD (HL-) A",
    "INC SP",
    "INC (HL)",
    "DEC (HL)",
    "LD (HL) d8",
    "SCF",
    "JR C r8",
    "ADD HL SP",
    "LD A (HL-)",
    "DEC SP",
    "INC A",
    "DEC A",
    "LD A d8",
    "CCF",
    "LD B B",
    "LD B C",
    "LD B D",
    "LD B E",
    "LD B H",
    "LD B L",
    "LD B (HL)",
    "LD B A",
    "LD C B",
    "LD C C",
    "LD C D",
    "LD C E",
    "LD C H",
    "LD C L",
    "LD C (HL)",
    "LD C A",
    "LD D B",
    "LD D C",
    "LD D D",
    "LD D E",
    "LD D H",
    "LD D L",
    "LD D (HL)",
    "LD D A",
    "LD E B",
    "LD E C",
    "LD E D",
    "LD E E",
    "LD E H",
    "LD E L",
    "LD E (HL)",
    "LD E A",
    "LD H B",
    "LD H C",
    "LD H D",
    "LD H E",
    "LD H H",
    "LD H L",
    "LD H (HL)",
    "LD H A",
    "LD L B",
    "LD L C",
    "LD L D",
    "LD L E",
    "LD L H",
    "LD L L",
    "LD L (HL)",
    "LD L A",
    "LD (HL) B",
    "LD (HL) C",
    "LD (HL) D",
    "LD (HL) E",
    "LD (HL) H",
    "LD (HL) L",
    "HALT",
    "LD (HL) A",
    "LD A B",
    "LD A C",
    "LD A D",
    "LD A E",
    "LD A H",
    "LD A L",
    "LD A (HL)",
    "LD A A",
    "ADD A B",
    "ADD A C",
    "ADD A D",
    "ADD A E",
    "ADD A H",
    "ADD A L",
    "ADD A (HL)",
    "ADD A A",
    "ADC A B",
    "ADC A C",
    "ADC A D",
    "ADC A E",
    "ADC A H",
    "ADC A L",
    "ADC A (HL)",
    "ADC A A",
    "SUB B",
    "SUB C",
    "SUB D",
    "SUB E",
    "SUB H",
    "SUB L",
    "SUB (HL)",
    "SUB A",
    "SBC A B",
    "SBC A C",
    "SBC A D",
    "SBC A E",
    "SBC A H",
    "SBC A L",
    "SBC A (HL)",
    "SBC A A",
    "AND B",
    "AND C",
    "AND D",
    "AND E",
    "AND H",
    "AND L",
    "AND (HL)",
    "AND A",
    "XOR B",
    "XOR C",
    "XOR D",
    "XOR E",
    "XOR H",
    "XOR L",
    "XOR (HL)",
    "XOR A",
    "OR B",
    "OR C",
    "OR D",
    "OR E",
    "OR H",
    "OR L",
    "OR (HL)",
    "OR A",
    "CP B",
    "CP C",
    "CP D",
    "CP E",
    "CP H",
    "CP L",
    "CP (HL)",
    "CP A",
    "RET NZ",
    "POP BC",
    "JP NZ a16",
    "JP a16",
    "CALL NZ a16",
    "PUSH BC",
    "ADD A d8",
    "RST 00H",
    "RET Z",
    "RET",
    "JP Z a16",
    "PREFIX CB",
    "CALL Z a16",
    "CALL a16",
    "ADC A d8",
    "RST 08H",
    "RET NC",
    "POP DE",
    "JP NC a16",
    "UNKNOWN",
    "CALL NC a16",
    "PUSH DE",
    "SUB d8",
    "RST 10H",
    "RET C",
    "RETI",
    "JP C a16",
    "UNKNOWN",
    "CALL C a16",
    "UNKNOWN",
    "SBC A d8",
    "RST 18H",
    "LDH (a8) A",
    "POP HL",
    "LD (C) A",
    "UNKNOWN",
    "UNKNOWN",
    "PUSH HL",
    "AND d8",
    "RST 20H",
    "ADD SP r8",
    "JP (HL)",
    "LD (a16) A",
    "UNKNOWN",
    "UNKNOWN",
    "UNKNOWN",
    "XOR d8",
    "RST 28H",
    "LDH A (a8)",
    "POP AF",
    "LD A (C)",
    "DI",
    "UNKNOWN",
    "PUSH AF",
    "OR d8",
    "RST 30H",
    "LD HL SP+r8",
    "LD SP HL",
    "LD A (a16)",
    "EI",
    "UNKNOWN",
    "UNKNOWN",
    "CP d8",
};
