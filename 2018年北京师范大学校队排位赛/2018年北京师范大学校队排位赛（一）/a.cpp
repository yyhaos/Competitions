//Problem Web:  https://codeforces.com/gym/225574/problem/A
#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
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
struct B
{
    ll l ,r,v;
    friend bool operator < (B a ,B b)
    {
        return a.l<b.l;
    }
};
B b[100005];
ll sum[100005];
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
ll k;
    mem(sum,0);
    mem(b,0);
    cin>>m>>k;
    rep(i,1,m)
    {
        scanf("%lld%lld%lld",&b[i].l,&b[i].r,&b[i].v);
    }

    sort(b+1,b+m+1);
//rep(i,1,m)
//{
//    cout<<b[i].l<<endl;
//}
    ll ans=0;
    rep(i,2,m+1)
    {
        sum[i]=sum[i-1]+(b[i-1].r-b[i-1].l+1LL)*b[i-1].v;
       // cout<<" sum["<<i<<"]="<<sum[i]<<endl;
    }
    //cout<<1<<endl;
    ll lef=0,rig=0;
    ll j=1;
    rep(i,1,m)
    {
        lef=b[i].l;
        rig=lef+k-1;
      //  cout<<lef<<"-"<<rig<<endl;
        while(b[j].r<=rig && j<=m)
        {
            j++;
        }
       // cout<<"i: "<<i<< " j:"<<j<<endl;
        ll tmp=0;
        if(i!=j)
        {
            tmp+=sum[j]-sum[i];
        }
       // cout<<"t1  "<<tmp<<endl;
        if(rig>=b[j].l && j<=m)
        {
            tmp+=(rig-b[j].l+1)*b[j].v;
        }
       // cout<<"t2  "<<tmp<<endl;
        ans=max(ans,tmp);
    }
    rep(i,1,m)
    {
        ll tmp=b[i].l;
        b[i].l=-b[i].r;
        b[i].r=-tmp;
    }
    sort(b+1,b+m+1);
     //ans=0;
    mem(sum,0);
    rep(i,2,m+1)
    {
        sum[i]=sum[i-1]+(b[i-1].r-b[i-1].l+1LL)*b[i-1].v;
       // cout<<" sum["<<i<<"]="<<sum[i]<<endl;
    }
    //cout<<1<<endl;
    lef=0,rig=0;
    j=1;
    rep(i,1,m)
    {
        lef=b[i].l;
        rig=lef+k-1;
     //   cout<<lef<<"-"<<rig<<endl;
        while(b[j].r<=rig && j<=m)
        {
            j++;
        }
       // cout<<"i: "<<i<< " j:"<<j<<endl;
        ll tmp=0;
        if(i!=j)
        {
            tmp+=sum[j]-sum[i];
        }
       // cout<<"t1  "<<tmp<<endl;
        if(rig>=b[j].l && j<=m)
        {
            tmp+=(rig-b[j].l+1)*b[j].v;
        }
      //  cout<<"t2  "<<tmp<<endl;
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
#ifdef use_t
}
#endif // use_t
    return 0;
}
