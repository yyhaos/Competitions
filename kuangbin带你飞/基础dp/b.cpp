#include<stdio.h>
#include<iostream>

#include <cstring>
#include <cstdio>
#include<algorithm>
using namespace std;
int a[1000005];
int main ()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int cnt=0;
        int pre=a[0];
        int tar=(1+n)/2;
        for(int i=1;i<n;i++)
        {
            if(pre==a[i])
            {
                cnt++;
            }
            else
            {
                if(cnt>=tar)
                {
                    printf("%d\n",a[i-1]);
                    cnt=0;
                    break;
                }
                else
                {
                    cnt=1;
                    pre=a[i];
                }
            }
        }
        if(cnt>=tar)
        {
            printf("%d",a[n-1]);
        }
    }
    return 0;
}
