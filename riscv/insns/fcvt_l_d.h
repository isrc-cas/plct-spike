require_extension('D');
require_rv64;
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(f64_to_i64(f64(FRS1_D), RM, true));
} else {
  WRITE_RD(f64_to_i64(f64(FRS1), RM, true));
}
set_fp_exceptions;
