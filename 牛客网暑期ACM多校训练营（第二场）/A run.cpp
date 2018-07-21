
#include <bits/stdc++.h>
using namespace std;
//https://www.nowcoder.com/acm/contest/140#question
typedef long long ll;
const int maxn = 1e5+6;
const int mod = 1000000007;
ll a[maxn][2],sum[maxn];
int q,k;

int main(){
    int n = 1e5+1;
    scanf("%d%d",&q,&k);
    sum[0] = 0;
    for (int i=1;i<k;i++){
        a[i][0] = a[i][1] = 1;
        sum[i] = (sum[i-1] + a[i][0])%mod;
    }
    a[k][1] = 1;
    a[k][0] = 1;
    sum[k] = (sum[k-1]+a[k][1]+a[k][0])%mod;
    for (int i=k+1;i<=n;i++){
        a[i][1] = a[i-k][0];
        a[i][0] = a[i-1][0] + a[i-1][1];
        sum[i] = (sum[i-1]+a[i][1]+a[i][0])%mod;
    }
    int l,r;
    while(q--){
        scanf("%d%d",&l,&r);
        printf("%lld\n",(sum[r]+mod-sum[l-1])%mod);
    }
    return 0;
}
