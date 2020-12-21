require_extension('F');
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_F(f32_mulAdd(f32(f32(FRS1_F).v ^ F32_SIGN), f32(FRS2_F), f32(FRS3_F)).v);
} else {
  WRITE_FRD(f32_mulAdd(f32(f32(FRS1).v ^ F32_SIGN), f32(FRS2), f32(FRS3)));
}
set_fp_exceptions;
