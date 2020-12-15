require_extension('F');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(sext32(FRS1_F.v[0]));
} else {
  WRITE_RD(sext32(FRS1.v[0]));
}
