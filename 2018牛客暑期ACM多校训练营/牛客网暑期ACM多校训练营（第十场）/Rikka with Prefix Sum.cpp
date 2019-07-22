#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5+6;
const ll mod = 998244353;

ll gcd(ll a,ll b){return (b==0)? a : gcd(b,a%b);}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

struct node{
    int x,k;
    ll w;
    node(int _x = 0, ll _w = 0, int _k = 0):x(_x),w(_w),k(_k){}
} t[maxn];

ll f[maxn], inv[maxn];
int tot, now;

void pre(){
    f[0]=inv[0]=inv[1]=1;
    for(int i=1;i<maxn;++i)f[i]=f[i-1]*i%mod;
    for(int i=2;i<maxn;++i)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    for(int i=2;i<maxn;++i)inv[i]=inv[i]*inv[i-1]%mod;
 //printf("%d\n",inv[i]);
}

ll C(int n,int m){
    if (n<m) return 0;
    if (m==1||m==n-1) return n;
    return f[n]*inv[m]%mod*inv[n-m]%mod;
}

ll query(int l,int r){
    ll ans = 0;
    for (int i=1;i<=tot;++i){
        int k = now-t[i].k;
        ans = (ans+t[i].w*C(r-t[i].x+k, k)%mod)%mod;
        ans = (ans+t[i].w*(mod-C(l-t[i].x+k-1,k)))%mod;
    }
    return ans;
}

int main(){
    pre();
    int T;
    scanf("%d",&T);
    while(T--){
        int n, m;
        scanf("%d%d",&n,&m);
        now = 0;
        tot = 0;
        for (int i=1;i<=m;i++){
            int op;
            scanf("%d",&op);
            if (op==2) ++now;
            else if (op==1){
                int l,r;
                ll w;
                scanf("%d%d%lld",&l,&r,&w);
                ll ww = w%mod;
                node wr;
                wr.k = now - 1;
                wr.x = l;
                wr.w = ww;
                t[++tot] = wr;
                if (r+1<=n) {
                    wr.k = now-1;
                    wr.x = r+1;
                    wr.w = (mod-ww)%mod;
                    t[++tot] = wr;
                }
            }else{
                int l,r;
                scanf("%d%d",&l,&r);
                printf("%lld\n",query(l,r));
            }
        }
    }
    return 0;
}
