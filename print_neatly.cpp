#include<iostream>
#include<math.h>
using namespace std;

long long sum_word_length(int left,int right,int *ls)//containing left and right
{
    long long re=0;
    for (int i=left;i<=right;i++)
    {
        re=re+ls[i];
    }
    return re;
}
long long every_turn()
{
    int n;
    cin>>n;
    int line_length;
    cin>>line_length;
    int value_lis[n];
    long long slop_lis[n];
    for( int i=0;i<n;i++)
    {
        cin>>value_lis[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        if(sum_word_length(i,n-1,value_lis)+n-1-i<=line_length)
        {
            slop_lis[i]=0;
        }
        else{
            long long cost=-1;
            for(int j=0;j<=n-2-i;j++)
            {
                if(sum_word_length(i,i+j,value_lis)+j<=line_length)
                {
                    if( (line_length-(sum_word_length(i,i+j,value_lis)+j)) * (line_length-(sum_word_length(i,i+j,value_lis)+j)) * 
                    (line_length-(sum_word_length(i,i+j,value_lis)+j)) +slop_lis[i+j+1]<cost  ||  cost==-1)
                    {
                        cost=(line_length-(sum_word_length(i,i+j,value_lis)+j)) * (line_length-(sum_word_length(i,i+j,value_lis)+j)) * 
                        (line_length-(sum_word_length(i,i+j,value_lis)+j)) +slop_lis[i+j+1];
                    }
                }
            }
            slop_lis[i]=cost;
        }
    }
    return slop_lis[0];
}
int main()
{
    int num;
    cin>>num;
    long long re[num];
    for (int i=0;i<num;i++)
    {
        re[i]=every_turn();
    }
    for(int i=0;i<num;i++)
    {
        cout<<re[i]<<endl;
    }
    return 0;
}
