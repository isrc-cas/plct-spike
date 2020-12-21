require_extension(EXT_ZFH);
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(sext32((int16_t)(FRS1_H.v[0])));
} else {
  WRITE_RD(sext32((int16_t)(FRS1.v[0])));
}
