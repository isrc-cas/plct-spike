require_extension('D');
require_fp;
softfloat_roundingMode = RM;
if (p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(f64_add(f64(RS1), f64(RS2)).v);
} else {
  WRITE_FRD(f64_add(f64(FRS1), f64(FRS2)));
}
set_fp_exceptions;
