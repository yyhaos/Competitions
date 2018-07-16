#include<bits/stdc++.h>
using namespace std;
struct d
{
    double w;
    double c;
}ds[205];
int dp[205];
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        int th=0;
        int n;
        scanf("%d",&n);
        double tw,tc;
        while(n--)
        {
            scanf("%lf%lf",&tw,&tc);
            ds[th].w=tw;
            ds[th++].c=tc;
        }
        int ans=-1;
        for(int i=0;i<th;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(ds[i].w>ds[j].w && ds[i].c<ds[j].c)
                {
                    if(dp[i]<1+dp[j])
                    {
                        dp[i]=1+dp[j];
                    }
                    //dp[i]=max(dp[i],1+dp[j]);
                }
            }
            if(ans<dp[i])
                ans=dp[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
