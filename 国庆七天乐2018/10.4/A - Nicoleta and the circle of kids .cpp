#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long gcd(long long a,long long b)
{
    if(b==0)
    return  a;
    else
    {
        return gcd(b,a%b);
    }
}
ll get(ll n,ll k)
{
    //if(gcd(n,k)==1)
    //    return n*k;
    ll g=gcd(n,k);
    ll cnt=n/g;
    return (n-g)*k+(k-1)*(g-1);
}
int main ()
{
    long long n,k;

    scanf("%lld%lld",&n,&k);
    ll ans=get(n,k);
    printf("%lld",ans);
    return 0;
}
