//Problem Web:https://vjudge.net/contest/330734#problem/A
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
struct sta
{
    ll v,pos;
    friend bool operator < (sta a,sta b)
    {
        return a.v<b.v;
    }
};//b[1100000];
struct sta2
{
    ll v,pos;
    friend bool operator < (sta2 a,sta2 b)
    {
        return a.v>b.v;
    }
}b[1100000],a[1100000];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
freopen("buffcraft.in","r",stdin);
freopen("buffcraft.out","w",stdout);

#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    ll v1,v2,k;
    cin>>v1>>k>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i].v);
        a[i].pos=i+1;
    }
    v2=100;
    for(int i=0;i<m;i++)
    {
        scanf("%lld",&b[i].v);
        b[i].pos=i+1;
    }

    sort(a,a+n);
    sort(b,b+m);

    ll sta=min(m,k);

    ll cha=k-sta;
    for(int i=0;i<sta;i++)
    {
        v2+=b[i].v;
    }
    for(int i=0;i<cha;i++)
    {
        v1+=a[i].v;
    }
    ll ans=0;
    ll ti=sta;
    ans=v1*v2;

//        printf("%lld %lld--%lld\n",v1,v2,v1*v2);
    for(int i=sta-1;i>=0;i--)
    {
        ll cha=k-i;
        if(cha-1<n)
            v1+=a[cha-1].v;
        v2-=b[i].v;
//        printf("%lld %lld--%lld\n",v1,v2,v1*v2);
        ans=max(ans,v1*v2);
        if(ans==v1*v2)
        {
            ti=i;
        }
    }
printf("%lld %lld\n", min(n, k-ti),ti );

    for(int i=0;i<min(n,k-ti) ;i++)
    {
        if(i)
            printf(" ");
        printf("%lld",a[i].pos);
    }

    printf("\n");
for(int i=0;i<ti;i++)
    {
        if(i)printf(" ");
        printf("%lld",b[i].pos);
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}


