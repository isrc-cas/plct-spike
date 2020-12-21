require_extension('D');
require_rv64;
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_FRD_D(f64(RS1).v);
} else {
  WRITE_FRD(f64(RS1));
}
