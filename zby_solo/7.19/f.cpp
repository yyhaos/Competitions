//Problem Web:
#include<bits/stdc++.h>
//#include<ext/rope>
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
struct celue
{
    ll s,p;
    celue(ll _s=0,ll _p=0)
    {
        s=_s;
        p=_p;
    }
    friend bool operator < (celue a,celue b)
    {
        return a.s<b.s;
    }
}cc[100005];
celue tc[100005];
ll cnt=0;
ll get(ll x,ll th)
{
    if(th>=cnt)
    {
        th=cnt-1;
    }
    if(th<0)
        th=0;
    if(cc[th].s>x)
    {
        x=cc[th].s;
    }
        return cc[th].p*x;
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

    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&cc[i].s,&cc[i].p);
    }
    cnt=0;
    ll cha=n-1;
//    tc[cnt++]=cc[cha];
    celue now=cc[cha];
    for(int i=n-2;i>=0;i--)
    {
        if(cc[i].p==now.p)
        {
            now=cc[i];
            continue;
        }
        if(now.p*now.s > cc[i].p*cc[i].s)
        {
            tc[cnt++]=now;
            now=cc[i];
        }
    }
    tc[cnt++]=now;

    for(int i=0;i<cnt;i++)
    {
        cc[i]=tc[cnt-i-1];
    }
//    for(int i=0;i<cnt;i++)
//    {
//        cout<<"cc:"<<i<<" "<<cc[i].s<<" "<<cc[i].p<<endl;
//    }




ll tmp,ans;
    for(int i=0;i<m;i++)
    {
        scanf("%lld",&tmp);
        ll po=lower_bound(cc,cc+cnt,celue(tmp,0))-cc;
        ans=min(get(tmp,po),get(tmp,po+1));
        ans=min(ans, get(tmp,po-1));
        cout<<ans<<"\n";
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}


