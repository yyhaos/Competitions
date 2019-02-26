//Problem Web:
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

ll t,n,m;
ll a[105];
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

cin>>n;
    rep(i,0,n-1)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll ans=0;
    for(int i=0;i<n;i+=2)
    {
        cout<<a[i]<<" ";
    }
    if(n%2==1)
    for(int i=n-2;i>=1;i-=2)
    {
        if(i-1)
        cout<<a[i]<<" ";
        else cout<<a[i];
    }
    else for(int i=n-1;i>=1;i-=2)
    {
        if(i-1)
        cout<<a[i]<<" ";
        else cout<<a[i];
    }


#ifdef use_t
}
#endif // use_t
    return 0;
}
