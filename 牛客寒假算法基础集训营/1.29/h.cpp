//Problem Web:  https://ac.nowcoder.com/acm/contest/330/H
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
const ll qq=1e9+7;
ll ksm(ll a,ll b)
{

    ll ans=1;
    while(b)
    {
       // cout<<b<<endl;
        if(b&1)
            ans=(ans*a)%qq;
        a=(a*a)%qq;
        b>>=1;
    }
    return ans%qq;
}
ll ni(ll xx)
{
    return ksm(xx,qq-2LL);
}
ll t,n,m,k,x;

int main ()
{
   // cout<<qq;
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

    cin>>n>>k>>x;
    ll p=x+1LL,q=99-x,m=100LL;
    ll aa=0;
    m=ksm(100,n-1LL);
    ll mi=ni(m),c=1LL;
    for(ll h=0;h<=k-1;h++)
    {
        aa=(aa+ksm(p,h)*ksm(q,n-h-1LL)%qq*c%qq)%qq;
        c=c*(n-h-1)%qq*ni(h+1)%qq;

    }
    cout<<aa*mi%qq;



#ifdef use_t
}
#endif // use_t
    return 0;
}
