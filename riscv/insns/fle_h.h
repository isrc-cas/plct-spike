require_extension(EXT_ZFH);
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(f16_le(f16(FRS1_H), f16(FRS2_H)));
} else {
  WRITE_RD(f16_le(f16(FRS1), f16(FRS2)));
}
set_fp_exceptions;
