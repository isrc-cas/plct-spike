require_extension(EXT_ZFH);
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_H(f16_sub(f16(FRS1_H), f16(FRS2_H)).v);
} else {
  WRITE_FRD(f16_sub(f16(FRS1), f16(FRS2)));
}
set_fp_exceptions;
