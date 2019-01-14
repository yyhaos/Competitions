//	yyhaos
//  Problem:

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define mem(a,b) memset(a, b, sizeof(a))
const ll q=998244353LL;
ll power(ll a,ll e){ll ans=1LL;while(e){if(e&1)ans=(ans*a)%q;a=a*a%q;e>>=1;}return ans%q;}
ll gcd(ll a,ll b){return b ? gcd(b, a%b) : a;}
const double eps=1e-8;
const ll maxn=1e6;
const ll mod=998244353LL;
ll A[5005];
ll ni(ll x)
{
    return power(x,mod-2) %q;
}
ll C(ll n,ll x)
{
    return A[x]*A[n-x]%mod*ni(A[n])%mod;
}
int main ()
{
    #ifdef yyhaos
        freopen("test.txt", "r", stdin);
    #endif
    A[1]=1LL;
    A[0]=1LL;
    for(ll i=1;i<=5000;i++)
    {
        A[i]=A[i]*i%mod;
    }
    ll p,s,r;
    cin>>p>>s>>r;
    ll ans=0;
    ll tmp=0;
    ll yu;
    ll shu;
    ll zong=C(r-s+p-1,p-1);
    ll nizong=ni(zong);
    rep(i,s,r)
    {
        //tmp=1;
        yu=r-i;
        shu=C(yu+p-2,p-2)*nizong%mod;
        if(i>yu)
            tmp=1;
        else if(i<yu/(p-1))
            tmp=0;
        else
        {

        }
        ans=ans+shu*tmp%mod;
        ans=ans%mod;
    }
    #ifdef yyhaos
        cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}


