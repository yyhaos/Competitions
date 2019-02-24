//Problem Web:  https://ac.nowcoder.com/acm/contest/330/G
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
ll fa[100005];
ll fi(ll a)
{
    if(fa[a]==a)
        return a;
    return fa[a]=fi(fa[a]);
}
bool un(ll a, ll b)
{
    if(fi(a)==fi(b))
        return false;
    fa[fi(b)]=fi(a);
    fi(b);
    return true;
}
struct l
{
    ll s,t,c;
    l(ll ss,ll tt ,ll cc)
    {
        s=ss,t=tt,c=cc;
    }
    friend bool operator < (l a,l b)
    {
        return a.c>b.c;
    }
};
ll t,n,m,k;
ll a[100005];
priority_queue<l> qq;
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
    cin>>n>>m>>k;
    rep(i,1,k)
    {
        fa[i]=i;
    }
    rep(i,1,n)
    {
        scanf("%lld",a+i);
    }
    ll x,y,c;

    rep(i,1,m)
    {
        scanf("%lld%lld%lld",&x,&y,&c);
        if(a[x]>k || a[x]<=0 || a[y]>k || a[y]<=0)
            continue;
        qq.push(l(a[x],a[y],c));
    }
    ll ans=0;
    while(!qq.empty())
    {
        l fro=qq.top();
        qq.pop();
        //cout<<fro.s<<" "<<fro.t<<" "<<fro.c<<endl;
        if(un(fro.s,fro.t))
        {
            ans+=fro.c;
        }
    }
    rep(i,1,k)
    {
        if(fi(i)!=fi(1))
        {
            cout<<"-1";
            return 0;
        }
    }
    cout<<ans;


#ifdef use_t
}
#endif // use_t
    return 0;
}
