require_extension(EXT_ZCE);
require(((xlen / 4 -1) & SP) == 0); // sp alignment
require(insn.rvzce_rlist() >= insn.rvzce_mv()); 
reg_t bytes = xlen >> 3;
reg_t ra = insn.rvzce_ra();
reg_t rlist = insn.rvzce_rlist();
reg_t mv = insn.rvzce_mv();
reg_t spimm = insn.rvzce_spimm();

if (rlist > 12)  //push.e
  rlist -= 10;
ZCE_PUSH(bytes, rlist, ra, spimm, mv);
