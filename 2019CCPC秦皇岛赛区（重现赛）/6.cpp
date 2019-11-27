//Problem Web:http://acm.hdu.edu.cn/showproblem.php?pid=6736
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
const ll q=998244353LL;
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
//ll q=998244353;
ll ans=1;

ll vis[300005];
ll t,n,m;
vector<ll> M[300005];
ll step[300005];
ll used=0;
void dfs(ll x)
{
    ll si=M[x].size();
    for(int i=0;i<si;i++)
    {
        ll nxt=M[x][i];
        if(vis[nxt]==0)
        {
            vis[nxt]=1;
            step[nxt]=step[x]+1;
            dfs(nxt);
        }
        else
        {
            if(step[nxt] < step[x])
                continue;
//            printf("%lld %lld %lld\n",x,step[x],step[nxt]);
            ll cnt=0;
            cnt=step[nxt]-step[x]+1;
//            printf("cnt:%lld\n",cnt);
            used+=cnt;
            ans*=(ksm(2,cnt)-1LL);
            ans%=q;
        }
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
ll u,v;
    while(~scanf("%lld%lld",&n,&m))
    {
        ans=1;
        for(int i=0;i<=n;i++)
        {
            step[i]=0;
            vis[i]=0;
            M[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            scanf("%lld%lld",&u,&v);
            M[u].push_back(v);
            M[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                step[i]=0;
                vis[i]=1;
                dfs(i);
            }
        }
        ans*=ksm(2,m-used);
        ans%=q;
        printf("%lld\n",ans);
    }







#ifdef use_t
}
#endif // use_t
    return 0;
}


