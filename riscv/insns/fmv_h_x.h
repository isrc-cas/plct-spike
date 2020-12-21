require_extension(EXT_ZFH);
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_H(f16(RS1).v);
} else {
  WRITE_FRD(f16(RS1));
}
