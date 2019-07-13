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
using namespace __gnu_cxx;
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
struct sta
{
    ll ok,pos;
    sta(ll _o=0,ll _p=0)
    {
        ok=_o;
        pos=_p;
    }
}st[1005];
ll ok[1005];
rope<sta> s;
ll lose[1005];
ll a[1005];
//ll st[1005];
ll ok2[1005];
ll _g(ll x,ll n)
{
    if(x>n)
        return x%n;
    if(x<0)
    {
        return (x+2*n)%n;
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
ll p;
    cin>>n>>p;
    for(ll i=0;i<n-1;i++)
    {
        scanf("%lld",a+i);
        a[i]%=(n-i);
    }
    for(ll i=0;i<n-1;i++)
    {
        scanf("%lld",lose+i);
    }
    mem(ok,0);
    ok[p]=1;
    for(ll i=0;i<=n;i++)
    {
        st[i].pos=i;
        st[i].ok=0;
    }
    st[p].ok=1;
    s.insert(0,st+1,n);
    for(int i=0;i<n;i++)
    {
        printf("%lld %lld\n",s.at(i).pos,s.at(i).ok);
    }
    for(int i=0;i<n-1;i++)
    {
        ll lo=lose[i];
        ll duo=a[i];
        ll si=n-i;

        for(int j=0;j<si;j++)
        {
            st[j].ok=0;
            st[j].pos=s.at(j).pos;
        }
        for(int j=0;j<si;j++)
        {
            if(s.at(j).ok)
            {
                ll yi1=_g(j+duo,si);
                ll yi2=_g(j-duo,si);
                st[yi1].ok=1;
                st[yi2].ok=1;
            }
        }
        s.erase(0,si);
        ll th;
        for(int i=0;i<n;i++)
        {
            if(s.at(i).pos==lo)
                th=i;
        }
        for(int i=th;i<n-1;i++)
        {
            st[i].pos=st[i+1].pos;
            st[i].ok=st[i+1].ok;
        }
        s.insert(0,st,si-1);
    }
    if(s.at(0).ok==1)
    {
        printf("Yes");
    }
    else
        printf("No");


#ifdef use_t
}
#endif // use_t
    return 0;
}

