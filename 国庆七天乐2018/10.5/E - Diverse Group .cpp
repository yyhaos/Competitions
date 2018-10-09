#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 10000002;
const int mod =  1000000007;
ll f[maxn],inv[maxn];

ll quekpow(ll a,ll b){
    ll ans = 1;
    while(b!=0){
        if(b & 1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return ans;
}

void init(){
    f[0]=inv[0]=inv[1]=1;
    for(int i=1;i<maxn;++i)f[i]=f[i-1]*i%mod;
    for(int i=2;i<maxn;++i)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    for(int i=2;i<maxn;++i)inv[i]=inv[i]*inv[i-1]%mod;
}

int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M,K;
        scanf("%d%d%d",&N,&M,&K);
        if(K > N){
            printf("0\n");
            continue;
        }
        ll ans = f[N]*inv[K]%mod*inv[N-K]%mod;
        ans = ans*quekpow(M,K)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
