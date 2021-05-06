require_extension(EXT_ZCE);
WRITE_RD(sext_xlen(MMU.load_int32(TP + insn.rvzce_lwimm())));
