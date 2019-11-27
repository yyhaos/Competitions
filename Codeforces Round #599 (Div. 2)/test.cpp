
#include<stdio.h>

void pi(int x)
{

    if(x==0)return ;
    pi(x/16);
    printf("%d",x%16);
    return ;
}
int main ()
{
    int n;
    scanf("%d",&n);
//    int ans=0;
    pi(n);
    if(n==0)printf("0");

    return 0;
}
