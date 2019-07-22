#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e5+6;
const ll mod = 998244353;
ll gcd(ll a,ll b){return (b==0)? a : gcd(b,a%b);}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll sum[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        mem(sum,0);
        ll n,m;
        scanf("%lld%lld",&n,&m);
        sum[0] = 0;
        for (int i=1;i<=n;i++){
            ll u;
            scanf("%lld",&u);
            sum[i] = (sum[i-1]+u)%mod;
        }
        int op;
        ll x,y;
        ll mm = m;
        while(mm--){
            scanf("%d%lld%lld",&op,&x,&y);
            if (op==1){
                continue;
            }else if (op==2){
                ll ans = (sum[y]+mod-sum[x-1])%mod;
                ll ppp = powmod(2,n*m,mod);
                ans =ans*ppp%mod;
                printf("%lld\n",ans);
            }
        }
    }

    return 0;
}
