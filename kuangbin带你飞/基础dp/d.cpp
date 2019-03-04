#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <cstdio>
using namespace std;
char na[20][105];
int n;
int out[20],cnt=0;
int C[120];
int c(int i)
{
    if(C[i]>0)
        return C[i];
    return C[i]=(1<<i);
}
int en[25];
int ne[25];
int dp[100000+50];
int main ()
{
    memset(C,0,sizeof(C));
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s%d%d",na[i],&en[i],&ne[i]);
        }
        for(int i=1;i<(1<<n);i++)
        {
            int time=0;
            for(int k=0;k<n;k++)
            {
                int i2=c(k);
                if(i2&i)
                {
                    time+=ne[k];
                }
            }
            int minn=2147483600;
            for(int k=n-1;k>=0;k--)
            {
                int i2=c(k);
                if(i2&i)
                {
                    int tem=0;
                    if(time>en[k])
                        tem=time-en[k];
             //       printf("%d - %d\n",k,tem);
                    minn=min(minn,dp[i-i2]+tem);
                }
            }
            dp[i]=minn;
      //      printf("i=%d time=%d dp=%d\n",i,time,dp[i]);
        }
        int te=(1<<n)-1;
        cnt=0;
        while(te>0)
        {
           // printf("te=%d\n",te);
            int time=0;
            for(int i=0;i<n;i++)
            {
                int k=c(i);
                if(te&k)
                {
                    time+=ne[i];
                }
            }
            for(int i=n-1;i>=0;i--)
            {
                int k=c(i);
                if(k&te)
                {
                    int fa=time-en[i];
                    if(fa<0)
                        fa=0;
                    if(dp[te-k]+fa==dp[te])
                    {
                        te=te-k;
                        out[cnt++]=i;
                     //   printf("out=%d te=%d\n",out[cnt-1],te);
                        break;
                    }
                }
            }
        }
        printf("%d\n",dp[(1<<n)-1]);
        for(int i=cnt-1;i>=0;i--)
            printf("%s\n",na[out[i]]);
    }
    return 0;
}
