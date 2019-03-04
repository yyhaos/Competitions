#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <cstdio>
//#include <bits/stdc++.h>
using namespace std;
int dp[100005][12];
int gt[100005][12];
int ra[100005][12];
int main ()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==0)
            return 0;
        memset(dp,0,sizeof(dp));
        memset(gt,0,sizeof(gt));
        memset(ra,0,sizeof(ra));
        int tx,tt;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&tx,&tt);
            ra[tt][tx]++;
        }
        n=100000;
        for(int t=1;t<=n;t++)
            for(int i=0;i<=11;i++)
            {
                gt[t][i]=ra[t][i];
                //printf("%d %d = %d\n",t,i,gt[t][i]);
            }
        //dp[1][5]=gt[1][5];
        for(int t=1;t<=n;t++)
        {
            for(int i=max(0,5-t);i<=min(11,5+t);i++)
            {
                int maxn=0;
                for(int k=-1;k<=1;k++)
                {
                    if(i+k>=0 && i+k<=11)
                    {
                        maxn=max(maxn,dp[t-1][i+k]);
                    }
                }
                dp[t][i]=maxn+gt[t][i];
             //   printf("%d %d = %d\n",t,i,dp[t][i]);
            }
        }
        int ans=0;
        for(int i=0;i<=10;i++)
        {
            ans=max(ans,dp[n][i]);
        }
        printf("%d\n",ans);
    }

    return 0;
}
