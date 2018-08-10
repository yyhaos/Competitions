#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const int maxn = 1e6+6;
const ll mod = 998244353;
ll n,m;
ll mod_pow(ll x,ll n){
    if (n==0) return 1;
    ll res = mod_pow(x*x%mod,n/2);
    if (n&1) res = res*x%mod;
    return res;
}

ll fac[maxn],inv[maxn];
void pre(){
    fac[0] = 1;
    for (int i=1;i<=maxn;i++){
        fac[i] = fac[i-1]*i%mod;
    }
    for (int i=0;i<=maxn;i++){
        inv[i] = mod_pow(fac[i],mod-2);
    }
}

ll C(int n,int m){
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

int main(){
    int T;
    pre();
    int cas = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&n,&m);
        ll ans = 0;
        if (m<=n){
            /*for (int i=0;i<n;i++){
                printf("fac %d %d\n",i,fac[i]);
                printf("inv %d %d\n",i,inv[i]);
            }*/
            ll cnt = 1;
            for (int k=1;k<=m;k++){
                if (k==1) cnt = 1;
                else cnt = (n-k+1)%mod*cnt%mod;
                ll r = C(m,k)*k%mod*cnt%mod;
                //printf("r %lld\n",r);
                ans=(ans+r)%mod;
            }
            //printf("%lld\n",ans);
        }else{
            ll cnt = 1;
            for (int k=1;k<=n;k++){
                if (k==1) cnt = m%mod;
                else cnt = (m-k+1)%mod*cnt%mod;
                ll r = C(n-1,k-1)%mod*cnt%mod;
                //printf("r %lld\n",r);
                ans=(ans+r)%mod;
            }
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
