require_extension('F');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  MMU.store_uint32(RS1 + insn.s_imm(), FRS2_F.v[0]);
} else {
  MMU.store_uint32(RS1 + insn.s_imm(), FRS2.v[0]);
}
