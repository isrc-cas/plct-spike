require_extension(EXT_ZCE);
WRITE_RD(RVZCE_RD - ( 1 << insn.rvzce_scale()));
if(RVZCE_RD != 0)
  set_pc(pc + insn.rvzce_brimm());
