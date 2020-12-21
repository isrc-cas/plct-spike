require_extension('D');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_D(fsgnj64(FRS1_D, FRS2_D, true, false).v);
} else {
  WRITE_FRD(fsgnj64(FRS1, FRS2, true, false));
}
