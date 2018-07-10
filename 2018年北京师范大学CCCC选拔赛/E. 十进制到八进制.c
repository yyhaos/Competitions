
#include<stdio.h>
int main ()
{
    int a;
    scanf("%d",&a);
    int th=0,ans[1000];
    while(a>0)
    {
        ans[th++]=a%8;
        a=a/8;
        //printf("%d %d %d\n",th,a,ans[th-1]);
    }
    while(th--)
    {
        printf("%d",ans[th]);
    }
    return 0;

}
