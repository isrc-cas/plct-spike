require_extension(EXT_ZFH);
require_rv64;
require_fp;
softfloat_roundingMode = RM;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_H(ui64_to_f16(RS1).v);
} else {
  WRITE_FRD(ui64_to_f16(RS1));
}
set_fp_exceptions;
