require_extension('D');
require_fp;
require_no_zfinx;
MMU.store_uint64(RS1 + insn.s_imm(), FRS2.v[0]);
