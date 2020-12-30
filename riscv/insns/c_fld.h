require_extension('C');
require_extension('D');
require_fp;
require_no_zfinx;
WRITE_RVC_FRS2S(f64(MMU.load_uint64(RVC_RS1S + insn.rvc_ld_imm())));
