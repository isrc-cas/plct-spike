require_extension('F');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(f32_eq(f32(FRS1_F), f32(FRS2_F)));
} else {
  WRITE_RD(f32_eq(f32(FRS1), f32(FRS2)));
}
set_fp_exceptions;
