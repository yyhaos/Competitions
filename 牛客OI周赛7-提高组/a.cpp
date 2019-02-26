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

ll t,n,m,k;
ll us[10]={6,2,5,5,4,5,6,3,7,6};
ll cal[50000005];
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

    cin>>n>>k;
    ll used=n/k;
mem(cal,0);
    rep(i,1,n)
    {
        cal[i]=cal[i/10]+us[i%10];
    }
    cal[0]=us[0];
    ll ans=0;
    used=used-4-cal[n];
    rep(i,0,n/2)
    {
        if(cal[i]+cal[n-i]==used)
            ans++;
        }
cout<<ans;
#ifdef use_t
}
#endif // use_t
    return 0;
}
