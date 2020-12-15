require_extension('D');
require_fp;
if(p->supports_extension(EXT_ZFINX)) {
  bool less = f64_lt_quiet(f64(FRS1_D), f64(FRS2_D)) ||
              (f64_eq(f64(FRS1_D), f64(FRS2_D)) && (f64(FRS1_D).v & F64_SIGN));
  if (isNaNF64UI(f64(FRS1_D).v) && isNaNF64UI(f64(FRS2_D).v))
    WRITE_FRD_D(f64(defaultNaNF64UI).v);
  else
    WRITE_FRD_D(less || isNaNF64UI(f64(FRS2_D).v) ? FRS1_D.v[0] : FRS2_D.v[0]);
} else {
  bool less = f64_lt_quiet(f64(FRS1), f64(FRS2)) ||
              (f64_eq(f64(FRS1), f64(FRS2)) && (f64(FRS1).v & F64_SIGN));
  if (isNaNF64UI(f64(FRS1).v) && isNaNF64UI(f64(FRS2).v))
    WRITE_FRD(f64(defaultNaNF64UI));
  else
    WRITE_FRD(less || isNaNF64UI(f64(FRS2).v) ? FRS1 : FRS2);
}

set_fp_exceptions;
