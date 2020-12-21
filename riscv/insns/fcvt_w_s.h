require_extension('F');
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(sext32(f32_to_i32(f32(FRS1_F), RM, true)));
} else {
  WRITE_RD(sext32(f32_to_i32(f32(FRS1), RM, true)));
}
set_fp_exceptions;
