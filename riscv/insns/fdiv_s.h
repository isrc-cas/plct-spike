require_extension('F');
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_F(f32_div(f32(FRS1_F), f32(FRS2_F)).v);
} else {
  WRITE_FRD(f32_div(f32(FRS1), f32(FRS2)));
}
set_fp_exceptions;
