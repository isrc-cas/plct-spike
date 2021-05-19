require_extension(EXT_ZCE);
require(((xlen / 4 -1) & SP) == 0); // sp alignment
reg_t bytes = xlen >> 3;
reg_t rlist = insn.rvzce_rlist();
reg_t spimm = insn.rvzce_spimm();
reg_t alist;
if (rlist > 12)  //push.e
  rlist -= 10;
alist = rlist <= 4 ? rlist : 4;
ZCE_PUSH(bytes, rlist, true, spimm, alist);
