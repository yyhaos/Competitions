#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <cstdio>
//#include <bits/stdc++.h>
using namespace std;

struct obj
{
    int w,v;
}a[505];

int dp[10005];
int e,f;

int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&e,&f);
        int tar=f-e;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].v,&a[i].w);
        }
        dp[0]=0;
        for(int i=1;i<=tar;i++)
        {
            dp[i]=-1;
        }
        for(int i=1;i<=tar;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>=a[j].w)
                {
                    if(dp[i]==-1 && dp[i-a[j].w]!=-1)
                        dp[i]=dp[i-a[j].w]+a[j].v;
                    else if(dp[i-a[j].w]!=-1)
                        dp[i]=min(dp[i],dp[i-a[j].w]+a[j].v);
                }
            }
            //printf("%d %d\n",i,dp[i]);
        }
        if(dp[tar]==-1)
        {
            printf("This is impossible.\n");
        }
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[tar]);
    }
    return 0;
}
