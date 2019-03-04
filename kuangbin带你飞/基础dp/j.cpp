#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <cstdio>
using namespace std;
struct S
{
    int s,w,th,dor;
}a[1005];
bool cmp(S a,S b)
{
    return a.w<b.w;
}
int ts,tw,cnt=0;
int dp[1005];

void dfs(int target,int now)
{
    for(int i=now-1;i>=0;i--)
    {
        if(dp[i]==target && a[now].s<a[i].s && a[now].w>a[i].w)
        {

            dfs(target-1,i);
           // printf("%d %d\n",target,now);
            printf("%d\n",a[i].th);
            return ;
        }
    }
}

int main ()
{
    //freopen("test.txt","r",stdin);
    dp[0]=1;

    while(~scanf("%d%d",&tw,&ts))
    {
        a[cnt].s=ts;
        a[cnt].th=cnt+1;
        a[cnt++].w=tw;
        dp[cnt-1]=1;
    }
    int ans=1;
    int en=0;
    sort(a,a+cnt,cmp);
    //printf("%d\n",cnt);
    dp[0]=1;
    for(int i=1;i<cnt;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j].s>a[i].s && a[j].w<a[i].w)
                dp[i]=max(dp[j]+1,dp[i]);
        }
        ans=max(ans,dp[i]);
        if(ans==dp[i])
        {
            en=i;
        }
        //printf("%d %d\n",i,dp[i]);
    }
    printf("%d\n",ans);
    dfs(ans-1,en);
    printf("%d\n",a[en].th);
    return 0;
}
