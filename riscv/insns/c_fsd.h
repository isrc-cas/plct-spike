require_extension('C');
require_extension('D');
require_fp;
require_no_zfinx;
MMU.store_uint64(RVC_RS1S + insn.rvc_ld_imm(), RVC_FRS2S.v[0]);
