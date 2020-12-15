require_extension('D');
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_D(f64_mulAdd(f64(f64(FRS1_D).v ^ F64_SIGN), f64(FRS2_D), f64(f64(FRS3_D).v ^ F64_SIGN)).v);
} else {
  WRITE_FRD(f64_mulAdd(f64(f64(FRS1).v ^ F64_SIGN), f64(FRS2), f64(f64(FRS3).v ^ F64_SIGN)));
}
set_fp_exceptions;
