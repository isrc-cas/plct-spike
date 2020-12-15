require_extension(EXT_ZFH);
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_H(i32_to_f16((int32_t)RS1).v);
} else {
  WRITE_FRD(i32_to_f16((int32_t)RS1));
}
set_fp_exceptions;
