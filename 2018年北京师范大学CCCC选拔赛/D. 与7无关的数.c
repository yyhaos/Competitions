#include<stdio.h>
int main ()
{
    int n,flag,sum=0,i ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        flag=0;
        if(i%7==0)
            continue;
        else if(i%10==7||i/10%10==7)
            continue;
        else
            sum+=i*i;
    }
    printf("%d",sum);
    return 0;
}
