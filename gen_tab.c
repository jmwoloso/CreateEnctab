#include "constsw.h"
void gen_tab(code_table,code_list,lower,upper)
unsigned char code_table[][TAB_SIZ];          
unsigned char code_list[];                    
int           lower;                          
int           upper;                          
{
  int idx;                                    
  int jdx;                                    
  for (idx = lower; idx < upper; idx++)
  {
    for (jdx = 0; jdx < TAB_SIZ; jdx++)     
    {
      code_table[idx][jdx] = code_list[jdx+1];
    }
    for (jdx = 0; jdx < TAB_SIZ; jdx++)     
    {
      code_list[jdx] = code_table[idx][jdx];
      code_list[jdx+TAB_SIZ] = code_table[idx][jdx];
    }
  }
}
