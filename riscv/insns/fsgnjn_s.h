require_extension('F');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_F(fsgnj32(FRS1_F, FRS2_F, true, false).v);
} else {
  WRITE_FRD(fsgnj32(FRS1, FRS2, true, false));
}
