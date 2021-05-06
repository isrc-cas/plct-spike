require_extension(EXT_ZCE);
require(((xlen / 4 -1) & SP) == 0); // sp alignment
reg_t bytes = xlen >> 3;
reg_t rlist = insn.rvzce_c_rlist();
reg_t spimm = insn.rvzce_c_spimm3();

ZCE_PUSH(bytes, rlist, true, spimm, 0);
