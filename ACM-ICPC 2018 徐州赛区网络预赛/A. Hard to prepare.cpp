#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod =1000000007;
ll dp[1000000+5][4];
ll ksm(ll a,ll b)
{
    ll ans=1,r=a;
    while(b>0)
    {
        if(b&1)
        {
            ans=ans*r%mod;
        }
        r=r*r%mod;
        b/=2;
    }
    return ans;
}
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        int n,k;
        scanf("%d%d",&n,&k);
        if(n==1)
        {
            printf("%lld\n",ksm(2,k));
            continue;
        }
        else if(n==2)
        {
            printf("%lld\n",ksm(2,k)*(ksm(2,k)-1)%mod);
            continue;
        }
        if(k==1)
        {
            printf("%lld\n",2LL);
            continue;
        }
        else
        {
            dp[2][1]=0;
            dp[2][2]=ksm(2,k);
            dp[2][3]=((ksm(2,k)-2)*ksm(2,k))%mod;
            for(int i=3;i<n;i++)
            {
                dp[i][1]=(dp[i-1][3]+dp[i-1][1])%mod;
                dp[i][2]=(dp[i-1][3]+dp[i-1][2])%mod;
                dp[i][3]=((ksm(2,k)-2)*dp[i-1][1])%mod;
                dp[i][3]=(dp[i][3]+(ksm(2,k)-2)*dp[i-1][2])%mod;
                dp[i][3]=(dp[i][3]+(ksm(2,k)-3)*dp[i-1][3])%mod;
            }
            ll ans=0;
            ans=ksm(2,k)-2;
            ans=(ans*dp[n-1][1])%mod;
            ans=(ans+(ksm(2,k)-1)*dp[n-1][2])%mod;
            ans=(ans+(ksm(2,k)-2)*dp[n-1][3])%mod;
            printf("%lld\n",(ans+mod)%mod);
        }
    }
    return 0;

}
