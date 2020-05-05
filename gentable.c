#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "constsw.h"
#include "structsw.h"
#include "protosw.h"
void main(argc,argv)                          
int  argc;                                    
char *argv[];                                 
{
  unsigned char arg_opts[3] = {'f','f','f'};  
  unsigned char code_table[TAB_SIZ][TAB_SIZ]; 
  unsigned char code_list[2*TAB_SIZ];         
  unsigned char fname[3][BUFSIZ] =            
                { ENC_FILE };
  FILE          *fpout;                       
  int           idx;                          
  if (args_ok(argc,argv,arg_opts,2,GEN_ERR,fname) &&
      filsopen(fname[0],&fpout,"wb"))
  {
    for (idx = 0; idx < TAB_SIZ; idx++)       
    {
      code_list[idx] = idx;
      code_list[idx+TAB_SIZ] = idx;
    }
    gen_tab(code_table,code_list,SHIFT,TAB_SIZ);
    gen_tab(code_table,code_list,0,SHIFT);
    fwrite(code_table,sizeof(code_table),1,fpout);
    closfils(&fpout);
    printf("\nEncryption Table created on file %s\n\n",fname[0]);
  }
}
