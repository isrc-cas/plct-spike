require_extension(EXT_ZFH);
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_H(f16(MMU.load_uint16(RS1 + insn.i_imm())).v);
} else {
  WRITE_FRD(f16(MMU.load_uint16(RS1 + insn.i_imm())));
}
