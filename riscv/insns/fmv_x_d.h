require_extension('D');
require_rv64;
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  WRITE_RD(FRS1_D.v[0]);
} else {
  WRITE_RD(FRS1.v[0]);
}
