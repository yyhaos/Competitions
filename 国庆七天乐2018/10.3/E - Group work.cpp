#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 6;
const int mod = 1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int main(){
    ll n;
    scanf("%I64d",&n);
    printf("%I64d\n",(1LL<<n)-n-1);
    return 0;
}
