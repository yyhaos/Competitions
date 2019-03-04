#include<stdio.h>
#include<iostream>
#include <cstring>
#include <cstdio>
#include<algorithm>
using namespace std;

int a[1000005];
int dp[1000005];
int maxn[1000005];

int main ()
{
    int m,n;
    while(~scanf("%d%d",&m,&n))
    {
        memset(dp,0,sizeof(dp));
        memset(maxn,0,sizeof(maxn));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int ans=-999999999;
        for(int i=1;i<=m;i++)
        {
            ans=-99999999;
            for(int j=i;j<=n;j++)
            {
                dp[j]=max(dp[j-1]+a[j],maxn[j-1]+a[j]);
                maxn[j-1]=ans;
                ans=max(ans,dp[j]);
            }
        }
        printf("%d\n",ans);
    }
}
