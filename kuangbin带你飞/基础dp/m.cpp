#include<stdio.h>
#include<iostream>
#include <cstring>
#include <cstdio>
#include<algorithm>
using namespace std;
struct plant
{
    int l,r,h;
}p[1005];
int dp[1005][5];
bool cmp(plant a,plant b)
{
    if(a.h!=b.h)
        return a.h>b.h;
    else
        return a.l<b.l;
}
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int ans=999999999;
        int n,x,y,h,H;
        scanf("%d%d%d%d",&n,&x,&h,&H);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].h);
        }
        sort(p,p+n,cmp);
        memset(dp,-1,sizeof(dp));
        int f1=1;
        for(int i=0;i<n;i++)
        {
            if(x>=p[i].l && x<=p[i].r  && f1==1)
            {
                f1=0;
                dp[i][1]=h-p[i].h+x-p[i].l;
                dp[i][2]=h-p[i].h-x+p[i].r;
            }
            if(dp[i][1]==-1 &&dp[i][2]==-1)
                continue;
            if(dp[i][1]!=-1)
            {
                if(dp[i][2]==-1)
                    dp[i][2]=dp[i][1]+p[i].r-p[i].l;
                else
                    dp[i][2]=min(dp[i][2],dp[i][1]+p[i].r-p[i].l);
            }
            if(dp[i][2]!=-1)
            {
                if(dp[i][1]==-1)
                    dp[i][1]=dp[i][2]+p[i].r-p[i].l;
                else
                    dp[i][1]=min(dp[i][1],dp[i][2]+p[i].r-p[i].l);
            }
            int fl=0,fr=0;
            for(int k=i+1;k<n;k++)
            {
                int ch=p[i].h-p[k].h;
                if(ch>H)
                    break;
                if(p[i].l>=p[k].l && p[i].l<=p[k].r && fl==0)
                {
                    fl=1;
                    if(dp[k][1]==-1)
                        dp[k][1]=ch+dp[i][1]+p[i].l-p[k].l;
                    else
                        dp[k][1]=min(dp[k][1],ch+dp[i][1]+p[i].l-p[k].l);
                    if(dp[k][2]==-1)
                        dp[k][2]=ch+dp[i][1]+p[k].r-p[i].l;
                    else
                        dp[k][2]=min(dp[k][2],ch+dp[i][1]+p[k].r-p[i].l);
                }
                if(p[i].r>=p[k].l && p[i].r<=p[k].r && fr==0)
                {
                    fr=1;
                    if(dp[k][1]==-1)
                        dp[k][1]=ch+dp[i][2]+p[i].r-p[k].l;
                    else
                        dp[k][1]=min(dp[k][1],ch+dp[i][2]+p[i].r-p[k].l);
                    if(dp[k][2]==-1)
                        dp[k][2]=ch+dp[i][2]+p[k].r-p[i].r;
                    else
                        dp[k][2]=min(dp[k][2],ch+dp[i][2]+p[k].r-p[i].r);
                }
            }
            if(p[i].h<=H && fl==0)
            {
                ans=min(ans,dp[i][1]+p[i].h);
            }
            if(p[i].h<=H && fr==0)
            {
                ans=min(ans,dp[i][2]+p[i].h);
            }
            if(i==n-1 && dp[i][1]>=0)
            {
                if(p[i].h<=H )
                {
                    ans=min(ans,dp[i][1]+p[i].h);
                }
                if(p[i].h<=H )
                {
                    ans=min(ans,dp[i][2]+p[i].h);
                }
            }
            //printf("%d %d\n",dp[i][1],dp[i][2]);
        }
        if(ans>=999999999)
            ans=h;
        printf("%d\n",ans);
    }
    return 0;
}
