require_extension(EXT_ZFH);
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(f16_classify(f16(FRS1_H)));
} else {
  WRITE_RD(f16_classify(f16(FRS1)));
}
