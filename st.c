#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};*/

const char *regs[] ={
  "s11","s10","t0"
};

int main()
{
  for(int i=0;i<32;i++)
  {
    char *mod=NULL;
    char t[20];
    strcpy(t,"$");
    printf("before connected, t is %s      ;",t);
    mod=strcat(t,regs[i]);
    printf("mod : %s, t : %s, compare result is %d\n",mod,t,strcmp(mod,"$t0"));
  }
  return 0;
}