#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll A[6500+5];
const ll mod=1e9+7;
ll n,m,K;   // n-t1-x m-t2-y

ll dp[85][85][6405];
//ll t3;
ll dfs(ll t1,ll t2,ll num)
{
    if(dp[t1][t2][num]>=0)
        return dp[t1][t2][num];

    if(t1==0 && t2==0)
    {
        return A[n*m-num];
    }
    ll tem=0;

    //ll num2=num+1;
    if(t1>0)
    {
       // num++;
        //ll number=;
        //ll temt1=;
        tem=(tem+(t1*(m-t2)*dfs(t1-1,t2,num+1)))%K;
    }
    if(t2>0)
    {
      //  num++;
       // ll number=;
        //ll temt2=;
        tem=(tem+(t2*(n-t1)*dfs(t1,t2-1,num+1)))%K;
    }
    //ll t3=;
    if((n-t1)*(m-t2)-num>0)
    {
        //ll number=t3;
        tem=(tem+((n-t1)*(m-t2)-num)*dfs(t1,t2,num+1))%K;
    }
    dp[t1][t2][num]=tem;
    return tem;
}

int main ()
{
   // freopen("result.txt","w",stdout);
    int t;

    scanf("%d",&t);
    while(t--)
    {

        memset(dp,-1,sizeof(dp));
        //K=1e9+7;
        //dp(79)
                scanf("%lld%lld%lld",&n,&m,&K);
                A[1]=1LL;
                for(ll i=2;i<=n*m+1;i++)
                {
                    A[i]=A[i-1]*i%K;
                }
                if(n<m)
                {
                    swap(n,m);
                }
                if(m==1)
                {
                    printf("%lld\n",A[n]%K);
                    continue;
                }
                ll ans=n*m%K;
                ans=ans*dfs(n-1,m-1,1)%K;

                printf("%lld\n",ans);
    }
    return 0;
}
