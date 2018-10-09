#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T,cas = 0;
ll x,l,n;

ll gcd(ll a,ll b){
    return (b==0)?a:gcd(b,a%b);
}

ll get(ll m){
    ll res = 0;
    for (ll i=1;i<=m;i*=2){
        ll s = min(2*i-1,m);
        ll rr = s-i+1;
        if (x<=rr*2-1) res++;
    }
    return res;
}

int main(){
    scanf("%d",&T);
    while(T--){
        ll p, q;
        scanf("%I64d%I64d%I64d",&x,&l,&n);
        p = get(n)-get(l-1);
        if (x%2==0) p = 0;
        if (x>l) p = p + x - l;
        q = n-l+1;
        printf("Case %d: ",++cas);
        int g = gcd(p,q);
        printf("%I64d/%I64d\n",p/g,q/g);
    }
    return 0;
}
