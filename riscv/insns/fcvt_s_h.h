require_extension(EXT_ZFH);
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_F(f16_to_f32(f16(FRS1_H)).v);
} else {
  WRITE_FRD(f16_to_f32(f16(FRS1)));
}
set_fp_exceptions;
