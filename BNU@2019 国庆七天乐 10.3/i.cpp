//Problem Web:
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
struct point
{
    ll x,y;
};
point p[1005];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("intel.in","r",stdin);
    freopen("intel.out","w",stdout);
#endif

#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    cin>>n;
    ll miy=INF,may=-INF,mix=INF,maxx=-INF;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&p[i].x,&p[i].y);
        miy=min(miy,p[i].y);
        may=max(may,p[i].y);
        mix=min(mix,p[i].x);
        maxx=max(maxx,p[i].x);

    }
    ll wai=may-miy+maxx-mix;
    wai*=2;
    ll nei=0;
    for(int i=0;i<n;i++)
    {
        ll ni=i+1;
        ni%=n;
        nei+= fabs(p[i].y-p[ni].y)+fabs(p[i].x-p[ni].x);
    }

    cout<<nei-wai;


#ifdef use_t
}
#endif // use_t
    return 0;
}



