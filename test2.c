#include <stdio.h>
int main()
{
  unsigned short a=0x8000;
  unsigned b=0xffff8000;
  if((short)a==b)
  {
    printf("a=%x\n",a);
    printf("(short)a= %x, b=%x\n",(short)a, b);
    printf("wo!!!\n");
  }
  return 0;
}