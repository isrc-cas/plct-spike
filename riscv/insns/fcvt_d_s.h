require_extension('D');
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_D(f32_to_f64(f32(FRS1_F)).v);
} else {
  WRITE_FRD(f32_to_f64(f32(FRS1)));
}
set_fp_exceptions;
