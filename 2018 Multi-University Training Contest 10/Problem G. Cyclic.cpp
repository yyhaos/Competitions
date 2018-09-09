#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef long long ll;
typedef pair<long long,int> pii;
const int maxn = 100000 + 6;
const ll mod = 998244353;
ll gcd(ll a,ll b){return (b==0)? a : gcd(b,a%b);}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

ll a[maxn];

int main(){
    int T;scanf("%d",&T);
    a[0]=1;
    a[1]=0;
    a[2]=0;
    a[3]=1;
    a[4]=1;
    a[5]=8;
    for (int i=5;i<=100001;i++){
        a[i] = ((i-3) * a[i-1]%mod + (2*a[i-2]%mod + a[i-3])%mod*(i-2)%mod)%mod;
    }
    while(T--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}


