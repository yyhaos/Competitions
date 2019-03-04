
#include<stdio.h>
#include<iostream>
#include <cstring>
#include <cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=1005;
int dp[maxn][maxn];
char a[maxn][maxn];
int main ()
{
    int n,ans;
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        ans=1;
        for(int i=0;i<n;i++)
            scanf("%s",a[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                dp[i][j]=1;
                if(i==0 || j==n-1)
                    continue;
                int m=dp[i-1][j+1];
                for(int th=1;th<=m;th++)
                {
                    if(a[i-th][j]==a[i][j+th])
                        dp[i][j]++;
                    else
                        break;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
