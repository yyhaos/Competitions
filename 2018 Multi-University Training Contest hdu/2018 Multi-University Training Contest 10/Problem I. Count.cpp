#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef long long ll;
typedef pair<long long,int> pii;
const int maxn = 4e7+6;
const ll mod = 998244353;
ll gcd(ll a,ll b){return (b==0)? a : gcd(b,a%b);}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

bool check[maxn];
int phi[maxn];
int prime[2433655+5];
ll ans[maxn];
int tot;

void phi_and_prime_table(){
    memset(check,false,sizeof(check));
    phi[1] = 1;
    tot = 0;
    for (int i=2;i<=maxn;i++){
        if (!check[i]){
            prime[tot++] = i;
            phi[i] = i-1;
        }
        for (int j=0;j<tot;j++){
            if (i*prime[j]>maxn) break;
            check[i*prime[j]] = true;
            if (i%prime[j]==0){
                phi[i*prime[j]] = phi[i]*prime[j];
                break;
            }else{
                phi[i*prime[j]] = phi[i]*(prime[j]-1);
            }
        }
    }
    //printf("%d",tot);
    //printf("%lld\n",phi[maxn-6]);
    int len = maxn/2;
    ans[1] = 0;
    for (int i=2;i<=len;i++){
        ans[i] = ans[i-1] + phi[i*2]/2;
    }
}
int main(){
    phi_and_prime_table();
    int T;scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}

