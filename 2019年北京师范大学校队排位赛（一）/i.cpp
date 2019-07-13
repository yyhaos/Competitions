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
//ll a[100005];
struct aa
{
    ll v,pos;
    aa (ll _v=0,ll _pos=0)
    {
        v=_v;
        pos=_pos;
    }
    friend bool operator <(aa a ,aa b)
    {
        return a.v>b.v;
    }
}a[100005];
ll sum[100005];
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
    ll A,cf,cm;
    cin>>n>>A>>cf>>cm>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",a+i);
        a[i]=aa(a[i],i);
    }
    sort(a,a+n);
    sum[0]=a[0].v;
    for(int i=1;i<n;i++)
    {
        sum[i]=sum[i-1]+a[i].v;
    }

    ll mn=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]==A)
            mn++;
        else
            break;
    }

    int Ac=n-mn;
    int yu=M;
    int ansi=0;
    int ans=0;
    for(int i=Ac;i>=0;i--)
    {
        int ma=n-i+1;
        yu=M-A+a[i].v;

        if(yu>=0)
        {
            ll l=0,r=A-1,mid;
            ll mii=r;
            while(r>l)
            {
                mid=(r+l)/2;
                aa tmp(mid,-1);
                ll pos=lower_bound(a,a+n,tmp)-a;
                while(pos>=0 && a[pos].v>=mid)
                    pos--;
                ll cost;
                if(pos>=0)
                    cost=mid*(pos+1)-sum[pos];
                else
                    cost=0;
                if(cost>yu)
                    l=mid+1;
                if(cost == yu)
                {
                    mii=mid;
                    break;
                }
                if(cost <yu)
                    r=mid-1;
            }
            for(int j=max(r,l); j >=min(r,l);j--)
            {
                mid=(r+l)/2;
                aa tmp(mid,-1);
                ll pos=lower_bound(a,a+n,tmp)-a;
                while(pos>=0 && a[pos].v>=mid)
                    pos--;
                ll cost;
                if(pos>=0)
                    cost=mid*(pos+1)-sum[pos];
                else
                    cost=0;
                if(cost <yu)
                {
                    mii=j+1;
                    break;
                }
            }
            if(mii*cm+ma*cf > ans)
            {
                ans=mii*cm+ma*cf;
                ansi=i;
            }

        }
        else
            break;
    }
    cout<<ans<<endl;
    for(int i=n-ansi+1;i<n;i++)
    {
        a[i].v=
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}
