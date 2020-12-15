require_extension('D');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_D(f64(MMU.load_uint64(RS1 + insn.i_imm())).v);
} else {
  WRITE_FRD(f64(MMU.load_uint64(RS1 + insn.i_imm())));
}

