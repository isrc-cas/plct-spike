require_extension('F');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  bool less = f32_lt_quiet(f32(FRS1_F), f32(FRS2_F)) ||
              (f32_eq(f32(FRS1_F), f32(FRS2_F)) && (f32(FRS1_F).v & F32_SIGN));
  if (isNaNF32UI(f32(FRS1_F).v) && isNaNF32UI(f32(FRS2_F).v))
    WRITE_FRD_F(f32(defaultNaNF32UI).v);
  else
    WRITE_FRD_F(less || isNaNF32UI(f32(FRS2).v) ? FRS1_F.v[0] : FRS2_F.v[0]);
} else {
  bool less = f32_lt_quiet(f32(FRS1), f32(FRS2)) ||
              (f32_eq(f32(FRS1), f32(FRS2)) && (f32(FRS1).v & F32_SIGN));
  if (isNaNF32UI(f32(FRS1).v) && isNaNF32UI(f32(FRS2).v))
    WRITE_FRD(f32(defaultNaNF32UI));
  else
    WRITE_FRD(less || isNaNF32UI(f32(FRS2).v) ? FRS1 : FRS2);
}
set_fp_exceptions;
