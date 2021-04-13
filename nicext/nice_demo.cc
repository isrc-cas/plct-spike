#include "extension.h"
#include "mmu.h"
#include "trap.h"
#include <cstring>
#define MAX_COL_NUM 4
struct : public arg_t {
  std::string to_string(insn_t insn) const {
    return xpr_name[insn.rs1()];
  }
} xrs1;

struct : public arg_t {
  std::string to_string(insn_t insn) const {
    return xpr_name[insn.rd()];
  }
} xrd;

static reg_t matrix_config;
static reg_t row_buffer[MAX_COL_NUM];
static reg_t custom_sbuf(processor_t* p, insn_t insn, reg_t pc)
{
  reg_t xs1 = RS1;
  for (reg_t i = 0; i <= matrix_config; i++) {
    p->get_mmu()->store_uint32(xs1 + 4 * i, row_buffer[i]);
  }
  return pc + 4; 
}

static reg_t custom_wsetup(processor_t* p, insn_t insn, reg_t pc)
{
  reg_t xs1 = RS1;
  if (xs1 > 3)
    throw trap_illegal_instruction(0);
  matrix_config = xs1;
  memset(row_buffer, 0, sizeof(row_buffer));
  return pc + 4; 
}

static reg_t custom_rowsum(processor_t* p, insn_t insn, reg_t pc)
{
  reg_t xs1 = RS1;
  reg_t rowsum = 0;
  reg_t data;
  for (reg_t i = 0; i <= matrix_config; i++) {
    data = p->get_mmu()->load_uint32(xs1 + 4 * i);
    rowsum += data;
    row_buffer[i] += data;
  }
  WRITE_RD(rowsum);
  return pc + 4; 
}

class nice_demo_t : public extension_t
{
 public:
  const char* name() { return "nice_demo"; }

  nice_demo_t() {}

  std::vector<insn_desc_t> get_instructions() {
    std::vector<insn_desc_t> insns;
    insns.push_back((insn_desc_t){0x0400207b, 0xFE00707F, custom_sbuf, custom_sbuf});
    insns.push_back((insn_desc_t){0x0800207b, 0xFE00707F, custom_wsetup, custom_wsetup});
    insns.push_back((insn_desc_t){0x0C00607b, 0xFE00707F, custom_rowsum, custom_rowsum});
    return insns;
  }

  std::vector<disasm_insn_t*> get_disasms() {
    std::vector<disasm_insn_t*> insns;
    insns.push_back(new disasm_insn_t("custom_sbuf", 0x0400207b, 0xFE00707F, {&xrs1}));
    insns.push_back(new disasm_insn_t("custom_wsetup", 0x0800207b, 0xFE00707F, {&xrs1}));
    insns.push_back(new disasm_insn_t("custom_rowsum", 0x0C00607b, 0xFE00707F, {&xrd, &xrs1}));
    return insns;
  }
};

REGISTER_EXTENSION(nice_demo, []() { return new nice_demo_t; })

