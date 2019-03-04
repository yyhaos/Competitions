#include<iostream>
#include<cstring>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct milk
{
    int s,e,w;
}m[1005];
int dp[1005];
bool cmp(milk a,milk b)
{
    if(a.s!=b.s)
        return a.s<b.s;
    else
        return a.e<b.e;
}
int main ()
{
    int k,n,r;
    memset(dp,0,sizeof(dp));
    scanf("%d%d%d",&k,&n,&r);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&m[i].s,&m[i].e,&m[i].w);
        m[i].e+=r;
    }
    sort(m,m+n,cmp);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int ts=m[i].s;
        dp[i]=m[i].w;
        for(int j=0;j<i;j++)
        {
            if(ts>=m[j].e)
                dp[i]=max(dp[i],dp[j]+m[i].w);
        }
        ans=max(ans,dp[i]);
        //printf("%d\n",dp[i]);
    }
    printf("%d",ans);
    return 0;
}
