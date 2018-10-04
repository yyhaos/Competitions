#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int maxn = 1e5 + 6;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

int a[maxn];
int ind[66];
int main(){
    ind[0] = 0;
    for (int i=1;i<32;i++){
        int j = i-1;
        ind[i] = 1<<j;
        //printf("%d\n",ind[i]);
    }
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int cnt = 0;
        int r = 1;
        int ans = -1;
        for (int i=0;i<32;i++){
            cnt = 0;
            if (ind[i]>a[r]){
                continue;
            }
            while(a[r]>=ind[i]&&a[r]<ind[i+1]){
                cnt++;
                r++;
            }
            ans = max(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}
