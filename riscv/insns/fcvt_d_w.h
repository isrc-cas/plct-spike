require_extension('D');
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_D(i32_to_f64((int32_t)RS1).v);
} else {
  WRITE_FRD(i32_to_f64((int32_t)RS1));
}
set_fp_exceptions;
