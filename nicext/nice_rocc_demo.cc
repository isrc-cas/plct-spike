#include "rocc.h"
#include "mmu.h"
#include <cstring>

#define MAX_COL_NUM 4
class nice_rocc_demo_t : public rocc_t
{
 public:
  const char* name() { return "nice_rocc_demo"; }

  reg_t custom3(rocc_insn_t insn, reg_t xs1, reg_t xs2)
  {
    reg_t rowsum = 0, data;
   
    switch (insn.funct)
    {
      case 2: // custom_sbuf
        for (reg_t i = 0; i <= matrix_config; i++) {
          p->get_mmu()->store_uint32(xs1 + 4 * i, row_buffer[i]);
        }
        break;
      case 4: // custom_wsetup
        if (xs1 > 3)
          illegal_instruction();
        matrix_config = xs1;
        memset(row_buffer, 0, sizeof(row_buffer));
        break;
      case 6: // custom_rowsum
        for (reg_t i = 0; i <= matrix_config; i++) {
          data = p->get_mmu()->load_uint32(xs1 + 4 * i);
          rowsum += data;
          row_buffer[i] += data;
        }
        break;
      default:
        illegal_instruction();
        break;
    }

    return rowsum;
  }

  nice_rocc_demo_t()
  {
    matrix_config = 0;
    memset(row_buffer, 0, sizeof(row_buffer));
  }

 private:
  reg_t matrix_config;
  reg_t row_buffer[MAX_COL_NUM];
};

REGISTER_EXTENSION(nice_rocc_demo, []() { return new nice_rocc_demo_t; })
