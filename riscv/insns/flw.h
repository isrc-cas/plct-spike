require_extension('F');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_F(f32(MMU.load_uint32(RS1 + insn.i_imm())).v);
} else {
  WRITE_FRD(f32(MMU.load_uint32(RS1 + insn.i_imm())));
}
