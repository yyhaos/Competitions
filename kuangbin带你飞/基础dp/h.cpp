#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <cstdio>
using namespace std;
int co[2005];
int co2[2005];
int dp[2005][3];
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(co,0,sizeof(co));
        memset(co2,0,sizeof(co2));
        memset(dp,0,sizeof(dp));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&co[i]);
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d",&co2[i]);
        }
        dp[1][1]=co[1];
        //dp[1][2]=co[1];
        for(int i=2;i<=n;i++)
        {
            dp[i][1]=min(dp[i-1][1]+co[i],dp[i-2][1]+co2[i-1]);
           // printf("%d %d %d\n",i,dp[i][1],dp[i][2]);
        }
        int s;
        s=dp[n][1];
      //  printf("%d\n",s);
        int mi=s/60;
        s=s%60;
        int h=mi/60;
       // printf("%d\n",s);
        mi%=60;
        h%=24;
        printf("%02d:%02d:%02d ",h+8,mi,s);
        if(h<=12)
            printf("am");
        else
            printf("pm");
        printf("\n");
    }
    return 0;
}
