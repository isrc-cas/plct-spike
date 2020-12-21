require_extension(EXT_ZFH);
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_H(f16_mulAdd(f16(FRS1_H), f16(FRS2_H), f16(f16(FRS3_H).v ^ F16_SIGN)).v);
} else {
  WRITE_FRD(f16_mulAdd(f16(FRS1), f16(FRS2), f16(f16(FRS3).v ^ F16_SIGN)));
}
set_fp_exceptions;
