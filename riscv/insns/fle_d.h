require_extension('D');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(f64_le(f64(FRS1_D), f64(FRS2_D)));
} else {
  WRITE_RD(f64_le(f64(FRS1), f64(FRS2)));
}
set_fp_exceptions;
