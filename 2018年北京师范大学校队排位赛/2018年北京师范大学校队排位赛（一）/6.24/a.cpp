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
struct bui
{
    ll l,r,v;
    void get()
    {
        scanf("%lld%lld%lld",&l,&r,&v);
    }
    friend bool operator < (bui a, bui b)
    {
        return a.l<b.l;
    }
}b[100005];

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
    ll k;
    cin>>m>>k;
    for(int i=1;i<=m;i++)
    {
        b[i].get();
    }
    sort(b+1,b+1+m);

    ll ans=0;
    ll tmp=0;
    ll tl,tr=1;
    tl=1;
    ll mr=0;
//    for(int i=1;i<=m;i++)
//    {
//        cout<<b[i].l<<" "<<b[i].r<<" "<<b[i].v<<endl;
//    }
//    cout<<endl;
    for(tl=1;tl<=m;tl++)
    {
        if(tl!=1)
        {
            tmp-=(b[tl-1].r-b[tl-1].l+1)*b[tl-1].v;
        }
        mr=k+b[tl].l-1;
        while(b[tr].r<=mr && tr<=m )
        {
            tmp+=(b[tr].r-b[tr].l+1)*b[tr].v;
            tr++;
        }

        int yu=1+mr-b[tr].l;
        if(tr>m)
            yu=0;
        if(yu<0)
            yu=0;
        ans=max(ans,tmp+yu*b[tr].v);
     //   cout<<ans<<' '<<tl<<" "<<tr<<' '<<tmp<<' '<<mr<<endl;

    }

    for(int i=1;i<=m;i++)
    {
        ll ttt=b[i].l;
        b[i].l=-b[i].r;
        b[i].r=-ttt;
    }
    sort(b+1,b+1+m);
   // ans=0;
    tmp=0;
    tl,tr=1;
    tl=1;
    mr=0;
//    for(int i=1;i<=m;i++)
//    {
//        cout<<b[i].l<<" "<<b[i].r<<" "<<b[i].v<<endl;
//    }
//    cout<<endl;
    for(tl=1;tl<=m;tl++)
    {
        if(tl!=1)
        {
            tmp-=(b[tl-1].r-b[tl-1].l+1)*b[tl-1].v;
        }
        mr=k+b[tl].l-1;
        while(b[tr].r<=mr && tr<=m )
        {
            tmp+=(b[tr].r-b[tr].l+1)*b[tr].v;
            tr++;
        }

        int yu=1+mr-b[tr].l;
        if(tr>m)
            yu=0;
        if(yu<0)
            yu=0;
        ans=max(ans,tmp+yu*b[tr].v);
     //   cout<<ans<<' '<<tl<<" "<<tr<<' '<<tmp<<' '<<mr<<endl;

    }


    cout<<ans<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}

