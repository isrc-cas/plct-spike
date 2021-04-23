require_extension(EXT_ZNICE);
reg_t xs1 = RS1;
reg_t rowsum = 0;
reg_t data;
for (reg_t i = 0; i <= p->rocc.matrix_config; i++) {
  data = MMU.load_uint32(xs1 + 4 * i);
  rowsum += data;
  p->rocc.row_buffer[i] += data;
}
WRITE_RD(rowsum);
