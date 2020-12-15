require_extension('F');
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_F(ui32_to_f32((uint32_t)RS1).v);
} else {
  WRITE_FRD(ui32_to_f32((uint32_t)RS1));
}
set_fp_exceptions;
