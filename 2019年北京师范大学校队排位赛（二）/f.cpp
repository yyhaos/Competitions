//Problem Web:
#include<bits/stdc++.h>
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
ll fb[2005][2005];
ll dp[2005][512];
ll e,k;

bool stahasth(ll sta,ll th)
{
    th+=4;
    return sta*(1<<th);
}
ll get(ll i,ll sta,ll j)
{
    if(j<i-e || j<0)
        return 0;
    if(j-i>e || j>=n)
        return 0;
    ll th=i-j;
    if(stahasth(sta,th))
        return 0;
    return dp[i-1][]
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
mem(fb,0);

    cin>>n>>e>>k;
    ll u,v;
    for(int i=1 ; i<=k;i++)
    {
        scanf("%lld%lld",&u,&v);
        fb[u][v]=1;//不能双向
    }
    ll off=4;
    ll maxn=1<<9;

    for(ll i=1;i<=n;i++)
    {
        ll nxt=i+1;
        for(ll now=0;now<maxn;now++)
        {
            ll nowst=i-e;
            ll nowed=i+e;
            if(nowst>=0)
            if(now&(1<<)//对应于第i-e位空的地方，
                continue;
            ll be=nxt-e;
            ll ed=nxt+e;
            be=max(0,be);
            ed=min(ed,n-1);//最多向上递归位置
            for(int cha=be;cha<=ed;cha++)
            {

            }
        }
    }


#ifdef use_t
}
#endif // use_t
    return 0;
}
