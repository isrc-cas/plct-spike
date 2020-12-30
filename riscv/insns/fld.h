require_extension('D');
require_fp;
require_no_zfinx;
WRITE_FRD(f64(MMU.load_uint64(RS1 + insn.i_imm())));

