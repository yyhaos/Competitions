#include<stdio.h>
#include<iostream>
#include <cstring>
#include <cstdio>
#include<algorithm>
using namespace std;
int a[1005];
int dp[1005];
int main ()
{
    int n;
    scanf("%d",&n);
    //while(~scanf("%d",&n))
   // {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<=n;i++)
            dp[i]=1;
        int ans=1;
        for(int i=1;i<n;i++)
        {
            for(int k=0;k<i;k++)
            {
                if(a[i]>a[k])
                    dp[i]=max(dp[i],dp[k]+1);
            }
            ans=max(ans,dp[i]);
        }

        printf("%d",ans);
 //   }
    return 0;
}
