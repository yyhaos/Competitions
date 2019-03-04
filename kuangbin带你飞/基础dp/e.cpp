#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <cstdio>
//#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,cnt;
ll a[1005];
long long dp[1005];
ll b;
ll mymax(ll a,ll b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main ()
{
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            //printf("%lld ",a[i]);
        }
        memset(dp,0LL,sizeof(dp));
        ll ans=0LL;
        for(int i=0;i<n;i++)
        {
            b=0LL;
         //   printf("b=%lld\n",b);
            for(int j=0;j<i;j++)
            {
                if(a[i]>a[j])
                    b=mymax(dp[j],b);
               // printf("%d-%lld\n",j,b);
                //dp[i]=mymax(dp[i],dp[j]);
            }
            b+=a[i];
            dp[i]=b;
            //printf("%d %lld %lld\n",i,dp[i],b);
            ans=mymax(ans,dp[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
