require_extension('D');
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_F(f64_to_f32(f64(FRS1_D)).v);
} else {
  WRITE_FRD(f64_to_f32(f64(FRS1)));
}
set_fp_exceptions;
