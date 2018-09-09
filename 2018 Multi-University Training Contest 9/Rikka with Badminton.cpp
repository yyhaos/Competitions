#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef long long ll;
typedef pair<long long,int> pii;
const int maxn = 1e5+6;
const ll mod = 998244353;
ll gcd(ll a,ll b){return (b==0)? a : gcd(b,a%b);}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}


int main(){
    int T;
    ll a,b,c,d;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        ll ans = 0;
        ans = ans + (b+d+1)*powmod(2,a+c,mod)%mod;
        ans%=mod;
        ans = ans + powmod(2,a+b,mod);
        ans%=mod;
        ans = mod + ans - ((b+1)*powmod(2,a,mod)%mod);
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}

