require_extension(EXT_ZNICE);
reg_t xs1 = RS1;
if (xs1 > 3)
  throw trap_illegal_instruction(0);
p->rocc.matrix_config = xs1;
memset(p->rocc.row_buffer, 0, sizeof(p->rocc.row_buffer));
