//Problem Web:https://ac.nowcoder.com/acm/contest/1072#question
#include<bits/stdc++.h>
#include<ext/rope> //using __gnu_cxx
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
ll N;
ll a[12][12];
ll dp[12][12];
ll getdp()
{
    mem(dp,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}
ll ya[12][12];
ll path[22];
void huanyuan()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=ya[i][j];
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
    ll x,y,z;
    while(cin>>x>>y>>z)
    {
        if(x==0)
            break;
        ya[x][y]=z;
    }

    for(int i=1;i<=n-1;i++)
    {
        path[i]=0;
    }
    for(int j=1;j<=n-1;j++)
    {
        path[n-1+j]=1;
    }

    ll ans=0;
    while(1)
    {
        ll tmp=0;
        ll sx=1,sy=1;
        huanyuan();
        for(int i=1;i<=2*n-2;i++)
        {
            tmp+=a[sx][sy];
            a[sx][sy]=0;
            if(path[i]==1)
            {
                sx++;
            }
            else
                sy++;
        }
        tmp+=a[sx][sy];
        a[sx][sy]=0;
        //cout<<endl;

        tmp+=getdp();
        ans=max(ans,tmp);
        if(!next_permutation(path+1,path+2*n-1))
            break;
    }
    cout<<ans<<endl;
#ifdef use_t
}
#endif // use_t
    return 0;
}



