def sum_word_length(left,right,a):
    re=0
    for i in range(left,right+1):
        re=re+a[i]
    return re

def single_turn():
    ls=input().split()
    n=eval(ls[0])
    line_length=eval(ls[1])
    value_lis=input().split()
    slop_lis=[]
    for i in range(0,n):
        value_lis[i]=eval(value_lis[i])
        slop_lis.append(-1)
    for i in range(n-1,-1,-1):
        if sum_word_length(i,n-1,value_lis)+n-1-i<=line_length:
            slop_lis[i]=0
        else:
            cost=-1
            for j in range(0,n-1-i):
                if sum_word_length(i,i+j,value_lis)+j<=line_length:
                    if (line_length-(sum_word_length(i,i+j,value_lis)+j))**3+slop_lis[i+j+1]<cost or cost==-1:
                        cost=(line_length-(sum_word_length(i,i+j,value_lis)+j))**3+slop_lis[i+j+1]
            slop_lis[i]=cost
    return slop_lis[0]

num=eval(input())
re=[]
for i in range(0,num):
    re.append(single_turn())
for i in range(0,num):
    print(re[i])