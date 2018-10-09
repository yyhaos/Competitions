#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
int a[1000005];
int main ()
{
    //freopen("test.txt","r",stdin);
    int n,t;
    scanf("%d%d",&n,&t);
    memset(dp,0,sizeof(dp));
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=t;j<=2*t;j++)
        {
            if(i-j>=1)
            {
                dp[i]=max(dp[i],dp[i-j]+a[i]);
                ans=max(ans,dp[i]);
            }
        }
        //printf("%d ",dp[i]);
    }
    printf("%d",ans);
    return 0;
}
