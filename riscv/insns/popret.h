require_extension(EXT_ZCE);
require(((xlen / 4 -1) & SP) == 0); // sp alignment
reg_t bytes = xlen >> 3;

reg_t rlist = insn.rvzce_rlist();
if (rlist > 12)  //pop.e
  rlist -= 10;

reg_t spimm = insn.rvzce_spimm();
reg_t ret_val = insn.rvzce_ret_val();
reg_t ra = insn.rvzce_ra();

ZCE_POP(bytes, rlist, ra, spimm, ret_val, true);
