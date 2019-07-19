#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    int tem[87];
    scanf("%d",&t);
    long long ans;
    long long dp[90][15];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<10;i++)
    {
        dp[1][i]=1LL;
    }
    for(int th=2;th<=82;th++)
    {
        for(int j=0;j<10;j++)
        {
            for(int i=j;i<10;i++)
            {
                dp[th][j]+=dp[th-1][i];
            }
           // printf("dp[%d][%d]=%d\n",th,j,dp[th][j]);
        }
    }
    while(t--)
    {
        ans=0LL;
        memset(tem,0,sizeof(tem));
        char str[87];
        scanf("\n%s",str);
        int len=0;
        for(len=0;str[len]!='\0';len++)
        {
            tem[len]=(int)str[len]-'0';
        }
        int flag=1;
        for(int j=0;j<len-1;j++)
        {
            if(tem[j]>tem[j+1])
            {
                //printf("-1\n");
                flag=0;
            }
        }
        if(flag==0)
        {
            printf("-1\n");
            continue;
        }
        if(len==1)
        {
            printf("%d\n",tem[0]);
        }
        else
        {
            int th=1;
            for(int j=len-1;j>=1;j--)
            {
                for(int k=tem[j-1];k<tem[j];k++)
                    ans+=dp[th][k];
                //printf("%d -- %lld\n",j,ans);
                th++;
            }
            for(int j=0;j<tem[0];j++)
            {
                ans+=dp[len][j];
              //  printf("%d - %lld\n",j,ans);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
