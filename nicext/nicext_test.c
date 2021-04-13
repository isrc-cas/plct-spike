#include <stdio.h>
#include <stdint.h>

#define _DEBUG_INFO_

#define ROW_LEN   3
#define COL_LEN   3

/** custom nice instruction sbuf */
void custom_sbuf(unsigned long * addr)
{
  int zero = 0;

  asm volatile(".insn r 0x7b, 2, 2, x0, %1, x0" : "=r"(zero) : "r"(addr));
}

/** custom nice instruction wsetup */
void custom_wsetup(int rownum)
{
  int zero = 0;

  asm volatile(".insn r 0x7b, 2, 4, x0, %1, x0" : "=r"(zero) : "r"(rownum));
}

/** custom nice instruction rowsum */
 int custom_rowsum(unsigned long *addr)
{
  int rowsum;

  asm volatile(".insn r 0x7b, 6, 6, %0, %1, x0" : "=r"(rowsum) : "r"(addr));

  return rowsum;
}

// normal test case without NICE accelerator.
void normal_case(unsigned int array[ROW_LEN][COL_LEN], unsigned int col_sum[COL_LEN], unsigned int row_sum[ROW_LEN])
{
  int i = 0, j = 0;

  unsigned int tmp = 0;
  for (i = 0; i < ROW_LEN; i++) {
    tmp = 0;
    for (j = 0; j < COL_LEN; j++) {
      col_sum[j] += array[i][j];
      tmp += array[i][j];
    }
    row_sum[i] = tmp;
  }
}


// teat case using NICE accelerator.
void nice_case(unsigned int array[ROW_LEN][COL_LEN], unsigned int col_sum[COL_LEN], unsigned int row_sum[ROW_LEN])
{
  int i;

  custom_wsetup(COL_LEN - 1);
  for (i = 0; i < ROW_LEN; i++) {
    row_sum[i] = custom_rowsum((unsigned long *)array[i]);
  }
  custom_sbuf((unsigned long *)col_sum);
}

void print_array(unsigned int array[ROW_LEN][COL_LEN])
{
  int i, j;
  printf("the element of array is :\r\n\t");
  for (i = 0; i < ROW_LEN; i++)
    printf("%d\t", array[0][i]);
  printf("\r\n\t");
  for (i = 0; i < ROW_LEN; i++)
    printf("%d\t", array[1][i]);
  printf("\r\n\t");
  for (i = 0; i < ROW_LEN; i++)
    printf("%d\t", array[2][i]);
  printf("\r\n\r\n");
}

void print_result(unsigned int col_sum[COL_LEN], unsigned int row_sum[ROW_LEN])
{
  int i, j;
  printf("the sum of each row is :\r\n\t\t");
  for (i = 0; i < ROW_LEN; i++)
    printf("%d\t", row_sum[i]);
  printf("\r\n");
  printf("the sum of each col is :\r\n\t\t");
  for (j = 0; j < COL_LEN; j++)
    printf("%d\t", col_sum[j]);
  printf("\r\n");
}

int compare_result(unsigned int ref_cs[COL_LEN], unsigned int ref_rs[ROW_LEN], \
  unsigned int nice_cs[COL_LEN], unsigned int nice_rs[ROW_LEN])
{
  int i, ret = 0;
  for (i = 0; i < COL_LEN; i ++) {
    if (ref_cs[i] != nice_cs[i]) {
#ifdef _DEBUG_INFO_
      printf("Column %d result not match: %d vs %d\r\n", ref_cs[i], nice_cs[i]);
#endif
      ret = -1;
    }
  }
  for (i = 0; i < ROW_LEN; i ++) {
    if (ref_rs[i] != nice_rs[i]) {
#ifdef _DEBUG_INFO_
      printf("Row %d result not match: %d vs %d\r\n", ref_rs[i], nice_rs[i]);
#endif
      ret = -1;
    }
  }
  return ret;
}

int main(void)
{
  unsigned int array[ROW_LEN][COL_LEN] = \
  {
    {10, 30, 90},
    {20, 40, 80},
    {30, 90, 120}
  };
  unsigned int col_sum_ref[COL_LEN] = {0};
  unsigned int row_sum_ref[ROW_LEN] = {0};
  unsigned int col_sum_nice[COL_LEN] = {0};
  unsigned int row_sum_nice[ROW_LEN] = {0};
  unsigned int begin_instret, end_instret, instret_normal, instret_nice;
  unsigned int begin_cycle, end_cycle, cycle_normal, cycle_nice;

  printf("\r\nNuclei Nice Acceleration Demonstration\r\n");

  printf("1. Print input matrix array\r\n");
  print_array(array);

  printf("2. Do reference matrix column sum and row sum\r\n");

  normal_case(array, col_sum_ref, row_sum_ref);

  printf("2. Do nice matrix column sum and row sum\r\n");

  nice_case(array, col_sum_nice, row_sum_nice);

  printf("3. Compare reference and nice result\r\n");
  printf("  1) Reference result:\r\n");
  print_result(col_sum_ref, row_sum_ref);
  printf("  2) Nice result:\r\n");
  print_result(col_sum_nice, row_sum_nice);
  printf("  3) Compare reference vs nice: ");

  if (compare_result(col_sum_ref, row_sum_ref, col_sum_nice, row_sum_nice) == 0) {
    printf("PASS\r\n");
  } else {
    printf("FAIL\r\n");
  }

  return 0;
}
