//	yyhaos
//  Problem:

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, n) for (ll i = (int)(a); i < (int)(n); ++i)
#define mem(a,b) memset(a, b, sizeof(a))
const ll q=1e9+7;
ll power(ll a,ll e){ll ans=1LL;while(e){if(e&1)ans=(ans*a)%q;a=a*a%q;e>>=1;}return ans%q;}
ll gcd(ll a,ll b){return b ? gcd(b, a%b) : a;}
const double eps=1e-8;
const ll maxn=1e6;
char s[200005];
ll c[200005];
ll dp[5][200005];
ll n;
char str[]="hard";
ll f(ll state,ll th)
{
    if(state==4LL)
        return 1LL<<62;
    if(th==n)
        return 0;

    else if(dp[state][th]>=0)
        return dp[state][th];
    else
    {
        if(s[th]==str[state])
        {
            dp[state][th]=min(f(state+1LL,th+1LL),f(state,th+1LL)+c[th]);
        }
        else
        {
            dp[state][th]=f(state,th+1LL);
        }
    }
    return dp[state][th];
}
int main ()
{
    #ifdef yyhaos
        freopen("test.txt", "r", stdin);
    #endif
    mem(dp,-1LL);

    cin>>n;
    scanf("%s",s);
   // cout<<s<<endl;
    rep(i,0,n)
        scanf("%lld",c+i);

    printf("%lld",f(0LL,0LL));

    #ifdef yyhaos
        cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}


