require_extension(EXT_ZNICE);
for (reg_t i = 0; i <= p->rocc.matrix_config; i++) {
    MMU.store_uint32(RS1 + 4 * i, p->rocc.row_buffer[i]);
}
