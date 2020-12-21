require_extension(EXT_ZFH);
require_rv64;
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(f16_to_i64(f16(FRS1_H), RM, true));
} else {
  WRITE_RD(f16_to_i64(f16(FRS1), RM, true));
}
set_fp_exceptions;
