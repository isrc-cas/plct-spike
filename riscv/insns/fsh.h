require_extension(EXT_ZFH);
require_fp;
require_no_zfinx;
MMU.store_uint16(RS1 + insn.s_imm(), FRS2.v[0]);
