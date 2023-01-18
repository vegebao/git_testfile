#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
  char x[10]="0x1123";
  int num=0;
  sscanf(x,"%x",&num);
  printf("%d\n",num);
}