//Problem Web:  https://ac.nowcoder.com/acm/contest/317/F
#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
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
ll dp[5005][5005];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    ll v;
    cin>>n>>v;
    mem(dp,0);
    rep(i,1,v)
    {
        dp[1][i]=1;
    }
    rep(i,2,n+1)
    {
        ll sum=1;
        rep(j,1,v)
        {
            sum+=dp[i-1][j-1]*(j-1);
            sum%=q;
            dp[i][j]=dp[i-1][j]+sum%q;
        }
    }

    ll ans=0;
    rep(i,1,v)
    {
        ans+=dp[n][i];
        ans%=q;
    }
    cout<<ans;


#ifdef use_t
}
#endif // use_t
    return 0;
}
