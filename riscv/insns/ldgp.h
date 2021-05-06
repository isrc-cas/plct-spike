require_extension(EXT_ZCE);
require_rv64;
WRITE_RD(sext_xlen(MMU.load_int64(GP + insn.rvzce_ldimm())));
