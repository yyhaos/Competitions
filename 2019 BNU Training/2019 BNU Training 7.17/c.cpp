//Problem Web:https://codeforces.com/contests/248218
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
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 1e15;
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
ll dp[2005][2005];
ll cost[2005];
ll cost_houzhui[2005];
ll a[2005];
ll b[2005];
ll cnt;
map<ll,ll>nt;
vector<ll> posa[2005];
vector<ll> posb[2005];

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
    for(int i=0;i<2005;i++)
    {
        posa.clear();
        posb.clear();
    }
    nt.clear();
    cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
        if(nt[a[i]]==0)
            nt[a[i]]=++cnt;
        posa[nt[a[i]]].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",b+i);
        if(nt[b[i]]==0)
        {
            nt[b[i]]=++cnt;
        }
        posb[nt[b[i]]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",cost+i);
    }
    for(int i=0;i<=n;i++)
    {
        if(i==0)
        {
            dp[i][0]=0;
        }
        else
        dp[i][0]=dp[i-1][0]+cost[i];
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=INF;
        }
    }
    cost_houzhui[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        cost_houzhui[i]=cost_houzhui[i+1]+cost[i];
    }
//    for(int i=1;i<=n;i++)
//    {
//        cout<<cost[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=1;i<=m;i++)
//    {
//        cout<<b[i]<<" ";
//    }
//    cout<<endl;


    for(int j=1;j<=m;j++)
    {
        for(int i=j;i<=n;i++)
        {
            dp[i][j]=dp[i-1][j]+cost[i];
            if(a[i]==b[j])
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            }
        }
    }

    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    ll ans=INF;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"£º"<<cost_houzhui[i+1]+dp[i][m]<<" "<<cost_houzhui[i+1]<<" "<<dp[i][m]<<endl;
        ans=min(ans,cost_houzhui[i+1]+dp[i][m]);
    }

    if(ans>=INF)
    {
        cout<<"No\n";
    }
    else
    cout<<ans<<"\n";





#ifdef use_t
}
#endif // use_t
    return 0;
}
