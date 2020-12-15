require_extension(EXT_ZFH);
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  MMU.store_uint16(RS1 + insn.s_imm(), FRS2_H.v[0]);
} else {
  MMU.store_uint16(RS1 + insn.s_imm(), FRS2.v[0]);
}
