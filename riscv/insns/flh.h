require_extension(EXT_ZFH);
require_fp;
require_no_zfinx;
WRITE_FRD(f16(MMU.load_uint16(RS1 + insn.i_imm())));
