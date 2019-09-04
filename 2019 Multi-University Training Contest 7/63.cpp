#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e6+10;
inline ll get(ll x)
{
     if(x<k || x>n)
        return INF;
    ll y= m/(1+x-k);
    while(y<=m/(1+x-k))
        y++;
    return x*y;
}
int main(void)
{
    int t;scanf("%d",&t);
    while(t--){
        LL n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
//        if(m<n){
//            LL ans = m+k;
//            printf("%lld\n",min(ans,n));
//            continue;
//        }
        LL last=n-k;
        LL mi=0,ma=m;
        while(mi<ma){
            int mid=(mi+ma)>>1;
            LL x = m-1ll*(mid+1)*last-mid;
            if(x>0) mi=mid+1;
            else ma=mid;
        }
        LL num = min(n,k+m/(mi+1));
        printf("%lld\n",1ll*num*(mi+1));
    }
}
