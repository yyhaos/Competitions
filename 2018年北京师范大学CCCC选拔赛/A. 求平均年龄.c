
#include<stdio.h>
int main ()
{
    int n;
    double tem,sum=0,th;
    scanf("%d",&n);
    th=n;
    while(n--)
    {
        scanf("%lf",&tem);
        sum+=tem;
    }
    printf("%.2f",sum/th);
    return 0;
}
