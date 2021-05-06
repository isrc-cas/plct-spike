require_extension(EXT_ZCE);
require(((xlen / 4 -1) & SP) == 0); // sp alignment
reg_t bytes = xlen >> 3;
reg_t spimm = insn.rvzce_c_spimm2();

ZCE_PUSH(bytes, 3, true, spimm, 0);
