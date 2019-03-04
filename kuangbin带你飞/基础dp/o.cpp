
#include<stdio.h>
#include<iostream>
#include <cstring>
#include <cstdio>
#include<algorithm>
using namespace std;
int dp[2005][2005];
int a[2005];
int main ()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        dp[i][i]=a[i]*n;
    for(int k=2;k<=n;k++)
    {
        int th=n-k+1;
        for(int l=0;l<n;l++)
        {
            int r=l+k-1;
            if(r>=n)
                break;
            dp[l][r]=max(a[l]*th+dp[l+1][r],a[r]*th+dp[l][r-1]);
        }
    }
    printf("%d",dp[0][n-1]);
    return 0;
}
