//Problem Web:  https://ac.nowcoder.com/acm/contest/331/F
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
ll N;
char str[3][1000005];
ll dp[3][10005];
ll orsum[3][1000005];

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
    mem(dp,0);
    mem(orsum,0);
    mem(str,0);
    scanf("%lld",&N);
    scanf("%s",str[1]);
    scanf("%s",str[2]);
    rep(i,0,2)
    {
        dp[i][0]=1;
    }
    ll ans=0;
    rep(i,1,N)
    {
        ll ii=i-1;
        rep(j,1,2)
            orsum[j][i]=orsum[j][ii]^(1<<(str[j][ii]-'0'));
        orsum[0][i]=orsum[0][ii]^(1<<(str[1][ii]-'0'))^(1<<(str[2][ii]-'0'));

        rep(j,0,2)
        {
            ans+=dp[j][orsum[j][i]];
            rep(k,0,9)
            {
                ans+=dp[j][orsum[j][i]^(1<<k)];
            }
        }
        rep(j,0,2)
        {
            dp[j][orsum[j][i]]++;
        }
    }
    cout<<ans;



#ifdef use_t
}
#endif // use_t
    return 0;
}
