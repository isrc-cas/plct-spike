require_extension('F');
require_rv64;
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_F(i64_to_f32(RS1).v);
} else {
  WRITE_FRD(i64_to_f32(RS1));
}
set_fp_exceptions;
