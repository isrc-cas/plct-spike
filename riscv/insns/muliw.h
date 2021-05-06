require_extension(EXT_ZCE);
require_rv64;
WRITE_RVZCE_RD(sext32((uint32_t)RVZCE_RS1 * (uint32_t)insn.rvzce_imm()));
