#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll INF = 1000000000000000006;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

int n,m,k;
char f[10];
ll a[1006];
ll dp[1006][10];
ll dp2[1006][10];
ll mx[10];
ll mi[10];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
        scanf("%s",f+1);
        for (int i=1;i<=10;i++) mx[i] = -INF,mi[i] = INF;
        for (int j=0;j<10;j++){
            for(int i=0;i<=1002;i++){
                if ( j==0  ){
                    dp[i][j] = k;
                }else dp[i][j] = -INF;
            }
        }
        for (int j=0;j<10;j++){
            for(int i=0;i<=1002;i++){
                if ( j==0  ){
                    dp2[i][j] = k;
                }else dp2[i][j] = INF;
            }
        }
        mx[0] = k;
        mi[0] = k;
        for (int j=1;j<=m;j++){
            for(int i=j;i<=n-m+j;i++){
                if (f[j]=='*'){
                    if(j==1)
                    {
                        dp[i][j]=max(dp[i-1][j],k*a[i]);
                    }
                    else
                        dp[i][j] = max(dp[i-1][j],max(dp2[i-1][j-1]*a[i],dp[i-1][j-1]*a[i]));
                    if(j==1)
                    {
                        dp2[i][j]=min(dp2[i-1][j],k*a[i]);
                    }
                    else
                        dp2[i][j] = min(dp2[i-1][j],min(dp2[i-1][j-1]*a[i],dp[i-1][j-1]*a[i]));
                }else if (f[j]=='/'){
                    if(j==1)
                    {
                        dp[i][j]=max(dp[i-1][j],k/a[i]);
                    }
                    else
                        dp[i][j] = max(dp[i-1][j],max(dp2[i-1][j-1]/a[i],dp[i-1][j-1]/a[i]));
                    if(j==1)
                    {
                        dp2[i][j]=min(dp2[i-1][j],k/a[i]);
                    }
                    else
                        dp2[i][j] = min(dp2[i-1][j],min(dp2[i-1][j-1]/a[i],dp[i-1][j-1]/a[i]));
                }else if (f[j]=='+'){
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]+a[i]);
                    dp2[i][j] = min(dp2[i-1][j],dp2[i-1][j-1]+a[i]);
                }else if (f[j]=='-'){
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]-a[i]);
                    dp2[i][j] = min(dp2[i-1][j],dp2[i-1][j-1]-a[i]);
                }
               // printf("%d %d - %d\n",i,j,dp[i][j]);
            }

        }
        ll ans = -INF;
        for (int i=m;i<=n;i++){
            ans = max(ans,dp[i][m]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
