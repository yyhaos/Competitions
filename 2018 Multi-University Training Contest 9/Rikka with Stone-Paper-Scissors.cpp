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
    ll a,b,c,a1,b1,c1;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&a,&b,&c);
        scanf("%lld%lld%lld",&a1,&b1,&c1);
        ll fm = a + b + c;
        ll fz = a*(b1-c1) + b*(c1 - a1) + c*(a1 - b1);
        if (fz%fm==0){
            fz/=fm;
            printf("%lld\n",fz);
        }else{
            ll g = gcd(fm,fz);
            fm/=g;
            fz/=g;
            if (fm<0){
                fz = 0 - fz;
                fm = 0 - fm;
            }
            printf("%lld/%lld\n",fz,fm);
        }
    }
    return 0;
}
