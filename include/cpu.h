#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define FLAGS_ZERO (1 << 7)
#define FLAGS_NEGATIVE (1 << 6)
#define FLAGS_HALFCARRY (1 << 5)
#define FLAGS_CARRY (1 << 4)

struct registers {
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
				uint8_t c;
				uint8_t b;
			};
			uint16_t bc;
		};
	};
	
	struct {
		union {
			struct {
				uint8_t e;
				uint8_t d;
			};
			uint16_t de;
		};
	};
	
	struct {
		union {
			struct {
				uint8_t l;
				uint8_t h;
			};
			uint16_t hl;
		};
	};
	
	uint16_t sp;
	uint16_t pc;
};

struct instruction {
  char *dissassembly;
  uint8_t operand_size;
  void (*fn)();
};

extern struct registers registers;
extern struct instruction instructions[256];

extern bool execute();
extern uint8_t add8(uint8_t a, uint8_t b);
extern uint8_t adc8(uint8_t a, uint8_t b, uint8_t c);
extern uint8_t sub8(uint8_t a, uint8_t b);
extern uint8_t subc8(uint8_t a, uint8_t b, uint8_t c);
extern void set_add_flags(uint8_t result, uint8_t a, uint8_t b);
extern void set_sub_flags(uint8_t result, uint8_t a, uint8_t b);
extern void set_logic_flags(uint8_t result);
extern void set_add16_flags(uint16_t result, uint16_t a, uint16_t b);

void nop();
void rst_38();

void inc_b();
void inc_c();
void inc_d(); 
void inc_e(); 
void inc_h(); 
void inc_l(); 
void inc_a(); 

void inc_af();
void inc_bc();
void inc_de();
void inc_hl();
void inc_sp();

void inc_hlm();

void dec_b();
void dec_c();
void dec_d();
void dec_e();
void dec_h();
void dec_l();
void dec_a();

void dec_af();
void dec_bc();
void dec_de();
void dec_hl();
void dec_sp();

void dec_hlm();

void ld_bc_n16();
void ld_b_n8();
void ld_c_n8();
void ld_de_n16();
void ld_d_n8();
void ld_e_n8();
void ld_hl_n16();
void ld_h_n8();
void ld_l_n8();
void ld_sp_n16();
void ld_hl_n8();
void ld_a_n8();

void ld_b_b();
void ld_b_c();
void ld_b_d();
void ld_b_e();
void ld_b_l();
void ld_b_h();
void ld_b_a();
void ld_c_b();
void ld_c_c();
void ld_c_d();
void ld_c_e();
void ld_c_h();
void ld_c_l();
void ld_c_a();
void ld_d_b();
void ld_d_c();
void ld_d_d();
void ld_d_e();
void ld_d_h();
void ld_d_l();
void ld_d_a();
void ld_e_b();
void ld_e_c();
void ld_e_d();
void ld_e_e();
void ld_e_h();
void ld_e_l();
void ld_e_a();
void ld_h_b();
void ld_h_c();
void ld_h_d();
void ld_h_e();
void ld_h_h();
void ld_h_l();
void ld_h_a();
void ld_l_b();
void ld_l_c();
void ld_l_d();
void ld_l_e();
void ld_l_h();
void ld_l_l();
void ld_l_a();
void ld_a_b();
void ld_a_c();
void ld_a_d();
void ld_a_e();
void ld_a_h();
void ld_a_l();
void ld_a_a();
void ld_c_a();
void ld_a_c();

void ld_a_hl();
void ld_b_hl();
void ld_c_hl();
void ld_d_hl();
void ld_e_hl();
void ld_h_hl();
void ld_l_hl();

void ld_hl_a();
void ld_hl_b();
void ld_hl_c();
void ld_hl_d();
void ld_hl_e();
void ld_hl_h();
void ld_hl_l();

void ld_hl_n8();

void ld_a_bcm();
void ld_a_dem();

void ld_bcm_a();
void ld_dem_a();

void ld_a_nn();
void ld_nn_a();

void ldh_a_c();
void ldh_c_a();
void ldh_a_n();
void ldh_n_a();

void ld_a_hld();
void ld_hld_a();
void ld_a_hli();
void ld_hli_a();

void ld_bc_nn();
void ld_af_nn();
void ld_de_nn();
void ld_hl_nn();

void ld_nn_sp();

void push_bc();
void push_af();
void push_de();
void push_hl();

void pop_bc();
void pop_af();
void pop_de();
void pop_hl();

void ld_hl_spe();

void add_a();
void add_b();
void add_c();
void add_f();
void add_d();
void add_e();
void add_h();
void add_l();
void add_hlm();
void add_n();

void adc_a();
void adc_b();
void adc_c();
void adc_f();
void adc_d();
void adc_e();
void adc_h();
void adc_l();
void adc_hl();
void adc_n();

void sub_a();
void sub_b();
void sub_c();
void sub_d();
void sub_e();
void sub_f();
void sub_h();
void sub_l();
void sub_hl();
void sub_n();

void scb_a();
void scb_b();
void scb_c();
void scb_d();
void scb_e();
void scb_f();
void scb_h();
void scb_l();
void scb_hl();
void scb_n();

void cp_a();
void cp_b();
void cp_c();
void cp_d();
void cp_e();
void cp_f();
void cp_h();
void cp_l();
void cp_hl();
void cp_n();

void and_a();
void and_b();
void and_c();
void and_d();
void and_e();
void and_f();
void and_h();
void and_l();
void and_hl();
void and_n();

void or_a();
void or_b();
void or_c();
void or_d();
void or_e();
void or_f();
void or_h();
void or_l();
void or_hl();
void or_n();

void xor_a();
void xor_b();
void xor_c();
void xor_d();
void xor_e();
void xor_f();
void xor_h();
void xor_l();
void xor_hl();
void xor_n();

void ccf();
void scf();
void daa();
void cpl();

void add_hl();
void add_sp();
void add_bc();
void add_de();
void add_af();
void add_sp_n();

void rlca();
void rrca();
void rla();
void rra();

void jp_nn();
void jp_hl();
void jp_nz_nn();
void jp_z_nn();
void jp_nc_nn();
void jp_c_nn();

void jr_e();
void jr_nz_e();
void jr_z_e();
void jr_nc_e();
void jr_c_e();
