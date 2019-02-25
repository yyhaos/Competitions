//Problem Web:  https://ac.nowcoder.com/acm/contest/317/E
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
const ll maxn=4000;
const ll L=1050;
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
ll a[maxn][maxn],b[maxn][maxn],c[maxn][maxn],d[maxn][maxn];
void mark_up(ll x,ll y,ll l)
{
    a[x-l/2][y]++;a[x+1][y-l/2-1]--;
    b[x-l/2][y+1]--;b[x+1][y+l/2+2]++;
}
void mark_down(ll x, ll y, ll l)
{
    c[x+1][y-l/2+1]++;c[x+l/2+1][y+1]--;
    d[x+1][y+l/2]--;d[x+l/2+1][y]++;
}
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
    ll qq;
    cin>>n>>m>>qq;
    ll opt,x,y,l;
    ll ans=0;
    rep(i,1,qq)
    {
        scanf("%lld%lld%lld%lld",&opt,&x,&y,&l);
        x+=L;
        y+=L;
        mark_up(x,y,l);
        if(opt==1)
        {
            mark_down(x,y,l);
        }
    }

    rep(i,0,maxn-2)
    {
        //cout<<i<<endl;
        ll tmp=0;
        rep(j,0,maxn-1)
        {
            tmp+=a[i][j]+b[i][j]+c[i][j]+d[i][j];
            if(i>L && i<=L+n && j>L && j<=L+m)
            {
           //     cout<<tmp<<" ";
                ans^=tmp;
            }
            a[i+1][j-1]+=a[i][j];
            b[i+1][j+1]+=b[i][j];
            c[i+1][j+1]+=c[i][j];
            d[i+1][j-1]+=d[i][j];
        }
      //  if(i>L && i<=L+n )
      //  cout<<endl;
    }
   cout<<ans;

#ifdef use_t
}
#endif // use_t
    return 0;
}
