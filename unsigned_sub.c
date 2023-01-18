#include <stdio.h>
int main()
{
    unsigned int a=0xffffffff;
    unsigned int b=1;
    unsigned c=a-b;
    printf("%d\n",a>0);
    printf("%d\n",c);
    printf("%x\n",c);
    return 0;
}
