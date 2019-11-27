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
ll id[10000];
ll nid=0;
ll fid(ll x)
{

}
struct node
{
    ll l,r,be,si;
    friend bool operator < (node a,node b)
    {
        return a.si<b.si;
    }
}nd[100005];

ll trans[100005];

map<ll,ll> sn;
ll cnts=1;
ll dfs(ll x)
{
    if(x==0)
        return -1;
    if(sn[x] !=0)
        return sn[x];
    else
        sn[x]=cnts++;

    if(x==1)
    {
        nd[sn[x]].l=nd[sn[x]].r=-1;
        nd[sn[x]].si=1;
        nd[sn[x]].be=sn[x];
        return sn[x];
    }
    ll mid,lx,rx;
    //mid=x/2;
    lx=x-x/2;
    rx=x/2;
//    cout<<lx<<" "<<rx<<" "<<x<<" "<<sn[x]<<endl;
    //if(lx!=0)
        nd[ sn[x]].l=dfs(lx);

   // else
   //     nd[sn[x]].l=-1;
  //  if(rx!=0)
        nd[ sn[x]].r=dfs(rx);
//    cout<<lx<<" "<<rx<<" "<<x<<" "<<sn[x]<<" "<<nd[sn[x]].l<<" - "<<nd[sn[x]].r<<endl;
  //  else
  //      nd[sn[x]].r=-1;
    nd[sn[x]].be=sn[x];
    nd[sn[x]].si=x;
//    if( lx==rx )
    return sn[x];
}
ll tran(ll x)
{
    if(x>=0)
        return trans[x];
    else
        return -1;
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

    sn.clear();
    cnts=1;
    cin>>n;
    dfs(n);
//for(int i=1;i<cnts;i++)
//    {
//
//      //  printf("%lld %lld\n",tran(nd[i].l),tran(nd[i].r));
//        printf("%lld %lld %lld+%lld\n",nd[i].l,nd[i].r, nd[i].be,nd[i].si);
//    }
    sort(nd+1,nd+cnts);
//    for(int i=1;i<cnts;i++)
//    {
//
//      //  printf("%lld %lld\n",tran(nd[i].l),tran(nd[i].r));
//        printf("%lld %lld %lld+%lld\n",nd[i].l,nd[i].r, nd[i].be,nd[i].si);
//    }
    for(int i=1;i<cnts;i++)
    {
        trans[nd[i].be]=i-1;
    }
    printf("%lld\n",cnts-1);
    for(int i=1;i<cnts;i++)
    {

        printf("%lld %lld\n",tran(nd[i].l),tran(nd[i].r));
//        printf("%lld %lld\n",nd[i].l,nd[i].r);

    }
    printf("%lld\n",cnts-2);


#ifdef use_t
}
#endif // use_t
    return 0;
}

