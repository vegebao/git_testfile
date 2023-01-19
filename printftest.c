#include<stdio.h>
#include<string.h>
#include<assert.h>

enum{CHAR,INT,
  STRING, NO_SPECIFIER
};

typedef struct NUM_FORMAT{
  char flag[5];
  char width;
  int wid_value;
  char precision;
  char length;
  char specifier;
} num_format;

void clear_info(num_format *t)
{
  for(int i=0;i<5;i++)
    t->flag[i]='N';
  t->width='N';
  t->wid_value=-1;
  t->precision='N';
  t->length='N';
  t->specifier='N';
}

int change_char_to_int(char* s)
{
  int sym=1;
  int re=0;
  int i=0;
  if(s[0]=='+')
  {
    sym=1;
    i++;
  }
  else if(s[0]=='-'){
    sym=-1;
    i++;
  }
  for(;s[i]!='\0';i++)
  {
    int did=0;
    for(int j=0;j<9;j++)
    {
      if('0'+j==s[i])
      {
        re=re*10+j;
        did=1;
      }
    }
    if(did==0)
      break;
  }
  re=re*sym;
  return re;
}

void change_unsigned_to_char(unsigned s, char* d)
{  
  int i=0;
  unsigned int res=0;
  do{
    res=s%10;
    d[i]='0'+res;
    s=s/10;
    i++;
  }while(s!=0);
  d[i]='\0';
}

void check_flag(const char *a, int *position, num_format *table)
{
  int t=0;
  while(t<5)
  {
    switch (a[*position])
    {
    case '0':{
      table->flag[t]='0';
      t++;
      *position=*position+1;
      break;
    }
    case '+':{
      table->flag[t]='+';
      t++;
      *position=*position+1;
      break;
    }
    case '-':{
      table->flag[t]='-';
      t++;
      *position=*position+1;
      break;
    }
    default:{
      table->flag[t]='N';
      break;
    }
    }
  }
}

void check_width(const char *a, int *position,num_format *table)
{
  if(a[*position]=='*')
  {
    table->width='*';
    *position=*position+1;
  }
  else{
    char ls[5];
    int index=0;
    for(int i=0;i<5;i++)
      ls[i]='N';
    while(1){
      int did=0;
      for(int j=0;j<10;j++)
      {
        if(a[*position]=='0'+j)
        {
          ls[index]=a[*position];
          *position=*position+1;
          index++;
          did=1;
          break;
        }
      }
      if(did==0)
        break;
    }
    ls[index]='\0';
    if(ls[0]!='N')
    {
      table->width='x';
      int num=strlen(ls);
      for(int i=0;i<num-1-i;i++)
      {
        char temp=ls[i];
        ls[i]=ls[num-i-1];
        ls[num-i-1]=temp;
      }
      table->wid_value=change_char_to_int(ls);
    }
    else{
      table->width='N';
    }
  }
}

void check_specifier(const char *a, int *position, num_format *table)
{
  switch (a[*position])
  {
    case 'd':{table->specifier=INT; *position=*position+1; break;}
    case 's':{table->specifier=STRING; *position=*position+1; break;}
    case 'c':{table->specifier=CHAR; *position=*position+1; break;}
    default:{table->specifier=NO_SPECIFIER; break;}
  }
}

void find_type(const char *a,int *position, num_format* table)
{
  clear_info(table);
  check_flag(a,position,table);
  check_width(a,position,table);
  check_specifier(a,position,table);
}

int myvsprintf(char *out, const char *fmt, va_list ap) {
  int num=0;
  int position1=0;
  int position2=0;
  while(fmt[position1]!='\0'){
    if(fmt[position1]!='%')
    {
      out[position2]=fmt[position1];
      position1++;
      position2++;
      num++;
    }
    else{
      while(fmt[position1+1]=='%')
      {
        out[position2]=fmt[position1];
        position1++;
        position2++;
        num++;
      }
      int remark=position1;//a[remark]='%'
      position1++;
      num_format table;
      clear_info(&table);
      find_type(fmt,&position1,&table);
      int have_0=0;
      for(int i=0;i<5;i++)
      {
        if(table.flag[i]=='0')
          have_0=1;
      }
      switch (table.specifier)
      {
        case INT:{
          int sam=va_arg(ap,int);
          if(have_0==1 && table.width=='x')
          {
            int wid=table.wid_value;
            if(sam<0)
            {
              out[position2]='-';
              position2++;
              num++;
              sam=-sam;
              wid=wid-1;
            }
            char str[16];
            change_unsigned_to_char(sam,str);
            int index=0;
            int res=wid-strlen(str);
            for(int i=0;i<res;i++)
            {
              out[position2]='0';
              num++;
              position2++;
            }
            while(str[index]!='\0')
            {
              out[position2]=str[index];
              index++;
              position2++;
              num++;
            }
          }
          else{
            if(sam<0)
            {
              out[position2]='-';
              position2++;
              num++;
              sam=-sam;
            }
            char str[16];
            change_unsigned_to_char(sam,str);
            int index=0;
            while(str[index]!='\0')
            {
              out[position2]=str[index];
              index++;
              position2++;
              num++;
            }
          }
          break;
        }
        case STRING:
        {
          int index=0;
          char *str=va_arg(ap,char*);
          while(str[index]!='\0')
          {
            out[position2]=str[index];
            position2++;
            index++;
            num++;
          }
          break;
        }
        case CHAR:
        {
          char t=va_arg(ap,char);
          out[position2]=t;
          position2++;
          num++;
          break;
        }
        case NO_SPECIFIER:
        {
          position1=remark;
          out[position2]=fmt[position1];
          position1++;
          position2++;
          num++;
          break;
        }
        default:
        {
          assert(0);
          break;
        }
      }
    }
  }
  out[position2]='\0';
  return num;
}

int mysprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap,fmt);
  return vsprintf(out,fmt,ap);
}

int main()
{
  int a=10;
  char str[30];
  mysprintf(" this is  %05d ",a);
  printf("%s\n",str);
  return 0;
}
