require_extension(EXT_ZCE);
if(RS1 == insn.rvzce_scmpimm())
  set_pc(pc + insn.rvzce_offset());
