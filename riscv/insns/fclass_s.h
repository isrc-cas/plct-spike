require_extension('F');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(f32_classify(f32(FRS1_F)));
} else {
  WRITE_RD(f32_classify(f32(FRS1)));
}
