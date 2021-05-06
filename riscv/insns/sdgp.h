require_extension(EXT_ZCE);
require_rv64;
MMU.store_uint64(GP + insn.rvzce_sdimm(), RS2);
