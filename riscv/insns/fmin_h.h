require_extension(EXT_ZFH);
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_H(f16_min(f16(FRS1_H), f16(FRS2_H)).v);
} else {
  WRITE_FRD(f16_min(f16(FRS1), f16(FRS2)));
}
set_fp_exceptions;
