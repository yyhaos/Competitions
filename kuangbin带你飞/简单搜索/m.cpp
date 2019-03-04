#include<stdio.h>
#include<iostream>

int gcd(int x,int y)
{
    if(x==0)
        return y;
    if(y==0)
        return x;
    if(x<y)
    {
        int tem=x;
        x=y;
        y=tem;
    }
    return x%y==0 ? y:gcd(y,x-y);
}
int main ()
{
    int n,m,s;
    while(~scanf("%d%d%d",&s,&n,&m))
    {
        if(s==0)
            break;
        int gc=gcd(n,m);
        s/=gc;
        if(s&1)
        {
            printf("NO\n");
        }
        else
            printf("%d\n",s-1);
    }
    return 0;
}
