require_extension('F');
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_F(f32_mulAdd(f32(FRS1_F), f32(FRS2_F), f32(f32(FRS3_F).v ^ F32_SIGN)).v);
} else {
  WRITE_FRD(f32_mulAdd(f32(FRS1), f32(FRS2), f32(f32(FRS3).v ^ F32_SIGN)));
}
set_fp_exceptions;
