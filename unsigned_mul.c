#include <stdio.h>

long long mul(long long a,long long b) {
	long long ans = a*b;
	return ans;
}

int main()
{
    int a=0xaeb1c2aa;
    int b=0xaeb1c2aa;
    long long c=mul(a,b);
    /*unsigned int d=(c>>32)&(0xffffffff);*/
    /*printf("a = %lx(%ld),  b = %lx(%ld) ,  c = %lx(%ld) , d = %x(%d)\n",a,a,b,b,c,c,d,d);*/
    if(c==0x19d29ab9db1a18e4LL)
    {
      printf("wo!!!\n");
    }
    if(c==0x7736200ddb1a18e4)
    {
      printf("en???\n");
    }
    return 0;
}
