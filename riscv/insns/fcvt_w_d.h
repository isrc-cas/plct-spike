require_extension('D');
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(sext32(f64_to_i32(f64(FRS1_D), RM, true)));
} else {
  WRITE_RD(sext32(f64_to_i32(f64(FRS1), RM, true)));
}
set_fp_exceptions;
