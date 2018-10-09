#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll q=1e9+7;
ll gcd(ll a ,ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a %q;
        }
        a=a*a%q;
        b/=2;
    }
    return ans;
}
ll an[1005];
int main ()
{
   // freopen("test.txt","r",stdin);
    ll n,m,c;
    scanf("%lld%lld%lld",&n,&m,&c);
    ll A=ksm(c,n*n);
    an[1]=A;
    ll ans=0;
    for(ll i=1;i<=m ;i++)
    {
        ll x=gcd(i,m);
        ans=(ans+ksm(c,n*n*x))%q;
    }
    ans=(ans*ksm(m,q-2))%q;
    printf("%lld\n",ans);

    return 0;
}
