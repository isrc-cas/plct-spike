require_extension(EXT_ZFH);
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_H(fsgnj16(FRS1_H, FRS2_H, false, false).v);
} else {
  WRITE_FRD(fsgnj16(FRS1, FRS2, false, false));
}
