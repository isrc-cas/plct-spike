require_extension('D');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(f64_classify(f64(FRS1_D)));
} else {
  WRITE_RD(f64_classify(f64(FRS1)));
}
