require_extension('F');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_F(f32(RS1).v);
} else {
  WRITE_FRD(f32(RS1));
}
