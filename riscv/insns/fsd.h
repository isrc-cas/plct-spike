require_extension('D');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  MMU.store_uint64(RS1 + insn.s_imm(), FRS2_D.v[0]);
} else {
  MMU.store_uint64(RS1 + insn.s_imm(), FRS2.v[0]);
}
