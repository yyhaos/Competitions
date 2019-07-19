//Problem Web:https://codeforces.com/gym/225575
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

//const off=1LL<<17;
ll t,n,m;
struct node
{
    ll l,r;
    double v;

}tr[300005+5];
double a[400000+15];

void buildtr(ll x,ll l,ll r)
{
    tr[x].l=l;
    tr[x].r=r;
    if(l==r)
    {
        tr[x].v=a[l];
        return ;
    }
    ll lch=x*2,rch=x*2+1;
    ll mid=(r+l)/2;
    buildtr(lch,l,mid);
    buildtr(rch,mid+1,r);
    tr[x].v=tr[x*2].v+tr[x*2+1].v;
}
void modify(ll x,ll pos,double val)
{
    if(tr[x].l==tr[x].r)
    {
        tr[x].v+=val;
        return ;
    }
    ll mid=(tr[x].l+tr[x].r)/2;
    if(pos<=mid)
        modify(x*2,pos,val);
    else
        modify(x*2+1,pos,val);
    tr[x].v=tr[x*2].v+tr[x*2+1].v;
}
double query(ll x,ll l ,ll r)
{
    if(l<=tr[x].l && tr[x].r<=r)
        return tr[x].v;
    ll mid=tr[x].l+tr[x].r;
    mid/=2;
    double ans=0;
    if(l<=mid)
        ans+=query(x*2,l,r);
    if(r>mid)
        ans+=query(x*2+1,l,r);
    return ans;
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
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&a[i]);
    }
    buildtr(1,1,n);

   // cout<<query(1,1,1)<<" "<<tr[1].v<<endl;
    ll q;

    cin>>q;
    ll ope;
    ll t1,t2;
    double tar;
    while(q--)
    {
        scanf("%lld",&ope);
        if(ope==1)
        {
            scanf("%lld%lf",&t1,&tar);
            double dis=-a[t1]+tar;
           // cout<<"dis: "<<dis<<endl;
           // cout<<"dis: "<<dis<<endl;
            a[t1]=tar;
            modify(1,t1,dis);
        }
        else
        {
            scanf("%lld%lld",&t1,&t2);
            double fen=1.0*t2-t1+1;
            double cnt=query(1,t1,t2);
            printf("%.10f\n",cnt/fen);
        }
    }


#ifdef use_t
}
#endif // use_t
    return 0;
}

