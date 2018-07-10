
#include<stdio.h>
int main ()
{
    int a,flag=1;
    scanf("%d",&a);
    if(a%4==0)
        if(a%100==0 && a%400!=0)
            flag=-1;
        else
            flag=1;
    else
        flag=-1;
    if(a%3200==0)
        flag=-1;
    if(flag==1)
        printf("Y");
    else
        printf("N");
    return 0;
}
