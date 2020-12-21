require_extension(EXT_ZFH);
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_H(f16_mulAdd(f16(f16(FRS1_H).v ^ F16_SIGN), f16(FRS2_H), f16(FRS3_H)).v);
} else {
  WRITE_FRD(f16_mulAdd(f16(f16(FRS1).v ^ F16_SIGN), f16(FRS2), f16(FRS3)));
}
set_fp_exceptions;
