//Problem Web:https://vjudge.net/contest/288637#problem/C
//#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
//#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
const ll q=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%q;
        a=a*a%q;
        b/=2LL;
    }
    return ans;
}

ll t,n,m;
ll a[1005];
ll dp[105][250][2];
ll DP(ll th,ll pre,ll type)
{
    if(dp[th][pre][type]!=-1)
    {
        return dp[th][pre][type];
    }
    else if(th==n+1)
    {
        return 0;
    }
    else if(th==1)
    {
        return dp[th][pre][type]=max(1+DP(th+1,a[1],type),DP(th+1,pre,type));
    }
    else if(type==1)
    {
        ll ma=DP(th+1,pre,1);
        if(a[th]>pre)
        {
            ma=max(ma,1+DP(th+1,a[th],1));
            ma=max(ma,1+DP(th+1,a[th],0));
        }
        ma=max(ma,DP(th+1,pre,0));
        return dp[th][pre][type]=ma;
    }
    if(type==0)
    {
        ll ma=0;
        ma=DP(th+1,pre,0);
        if(a[th]<pre)
        {
            ma=max(ma,DP(th+1,a[th],0)+1);
        }
        return dp[th][pre][type]=ma;
    }
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<105;i++)
    {
        for(int j=0;j<250;j++)
        {
            for(int k=0;k<2;k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
    cout<<n-DP(1,0,1);



#ifdef use_t
}
#endif // use_t
    return 0;
}
