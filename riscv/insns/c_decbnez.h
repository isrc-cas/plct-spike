require_extension(EXT_ZCE);
WRITE_RVZCE_C_RD(RVZCE_C_RS1 - ( 1 << insn.rvzce_c_scale()));
if(RVZCE_C_RS1 != 0)
  set_pc(pc - insn.rvzce_nzimm());
