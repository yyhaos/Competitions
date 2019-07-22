#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007, inv = 570000004;

ll gcd(ll a,ll b){return (b==0)? a : gcd(b,a%b);}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int maxn = 1006;

ll a[maxn], pm[maxn], pre[maxn][maxn];

int main(){
    ll n,m;
    ll ans = 0;
    scanf("%lld%lld",&n,&m);
    a[0] = a[n+1] = 0;
    for (int i=1;i<=n;i++) scanf("%lld", &a[i]),pm[i] = powmod(i,m,mod);
    //printf("%lld\n",powmod(100,mod-2,mod));
    for (int i=1;i<=n;i++){
        pre[i][i] = a[i]%mod*inv%mod;
        for (int j=i+1;j<=n;j++){
            pre[i][j] = pre[i][j-1]*a[j]%mod*inv%mod;
        }
    }
    for (int i=0;i<=n;i++){
        for (int j=i+2;j<=n+1;j++){
            ans += pre[i+1][j-1]*pm[j-i-1]%mod*(100-a[i])%mod*inv%mod*(100-a[j])%mod*inv%mod;
            ans %= mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
