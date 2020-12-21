require_extension('D');
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_D(f64_mul(f64(FRS1_D), f64(FRS2_D)).v);
} else {
  WRITE_FRD(f64_mul(f64(FRS1), f64(FRS2)));
}
set_fp_exceptions;
