//	yyhaos
//  Problem:

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define mem(a,b) memset(a, b, sizeof(a))
const ll q=1e9+7;
ll power(ll a,ll e){ll ans=1LL;while(e){if(e&1)ans=(ans*a)%q;a=a*a%q;e>>=1;}return ans%q;}
ll gcd(ll a,ll b){return b ? gcd(b, a%b) : a;}
const double eps=1e-8;
const ll maxn=1e6;

    char t[200005];
int main ()
{
    #ifdef yyhaos
        freopen("test.txt", "r", stdin);
    #endif

    int n;
    cin>>n;
    char fi,la;
    scanf("%s",t);
    fi=t[0];
    la=t[n-1];
    ll cnt1=0,cnt2=0;
    rep(i,0,n)
    {
        if(t[i]==fi)
            cnt1++;
        else
            break;
    }
    rep(i,0,n)
    {
        if(t[n-1-i]==la)
            cnt2++;
        else
            break;
    }
   // cout<<cnt1<<cnt2<<endl;
    if(fi==la)
    {
        printf("%lld\n",((cnt1+1LL)*(cnt2+1LL))%998244353LL);
    }
    else
    {
        printf("%lld\n",(cnt1+cnt2+1LL)%998244353LL);
    }
    #ifdef yyhaos
        cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}
