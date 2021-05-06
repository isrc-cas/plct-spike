require_extension(EXT_ZCE);
require(((xlen / 4 -1) & SP) == 0); // sp alignment
reg_t bytes = xlen >> 3;
reg_t spimm = insn.rvzce_c_spimm2();
reg_t ret_val = insn.rvzce_e_ret0();

ZCE_POP(bytes, 5, true, spimm, ret_val, true);
