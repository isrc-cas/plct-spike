require_extension(EXT_ZCE);
reg_t tbljalvec = (STATE.prv == PRV_U) ? STATE.utbljalvec :
                  (STATE.prv == PRV_S) ? STATE.stbljalvec :
                                         STATE.mtbljalvec; 
uint8_t mode = get_field(tbljalvec, TBLJALVEC_MODE);
uint8_t scale = get_field(tbljalvec, TBLJALVEC_SCALE);
reg_t base = get_field(tbljalvec, TBLJALVEC_BASE);
reg_t index = insn.rvzce_index8();
reg_t target;
switch (mode) {
case 0: //jump table mode
  if (xlen == 32)
    target = sext_xlen(MMU.load_uint32(base + (insn.rvzce_index8() << 2)));
  else // xlen = 8
    target = sext_xlen(MMU.load_uint64(base + (insn.rvzce_index8() << 3)));
  if (index < 8) // t0
    WRITE_REG(5, npc);
  else if (index < 64) //zero
    WRITE_REG(0, npc);
  else
    WRITE_REG(1, npc);
  set_pc(target & ~reg_t(1));
  break;
case 1: // TODO: Vector Table Mode
  break;
case 2: // TODO: Emulation Mode
  break;
default:
  require(0);
  break;
}


