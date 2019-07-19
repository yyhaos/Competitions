//Problem Web:  https://codeforces.com/gym/225575/problem/F
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
const ll maxn=100005;
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
vector<ll> M[100005];
ll t,n,m;
ll dp[maxn][2];

ll dfs(ll now,ll pre)
{
    dp[now][0]=0;
    dp[now][1]=1;
    for(int i=0;i<M[now].size();i++)
    {
        ll to=M[now][i];
        if(to==pre)
            continue;
        dfs(to,now);
        dp[now][0]+=max(dp[to][0],dp[to][1]);
        dp[now][1]+=dp[to][0];
    }
    return 0;
}
int main ()
{
    mem(dp,-1);
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
    ll a,b;
    cin>>n>>m;
    rep(i,1,m)
    {
        cin>>a>>b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    dfs(1,1);
    cout<<max(dp[1][1],dp[1][0]);




#ifdef use_t
}
#endif // use_t
    return 0;
}


