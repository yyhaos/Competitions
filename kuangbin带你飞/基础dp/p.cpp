
#include<stdio.h>
#include<iostream>
#include <cstring>
#include <cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int dp[105][105];
int a[105][105];
int n,k;
int dfs(int x,int y)
{
    if(dp[x][y])
        return dp[x][y];
    dp[x][y]=a[x][y];
    int fx=x,fy=y;
    for(x=fx-k;x<=fx+k;x++)
    {
        //int cnt=abs(x-fx)+abs(y-fy);
        if(x<0|| x>=n || y<0||y>=n)
            continue;
        if(a[x][y]<=a[fx][fy])
            continue;
        dp[fx][fy]=max(dp[fx][fy],dfs(x,y)+a[fx][fy]);
    }
    x=fx;
    for(y=fy-k;y<=fy+k;y++)
    {
        //int cnt=abs(x-fx)+abs(y-fy);
        if(x<0|| x>=n || y<0||y>=n)
            continue;
        if(a[x][y]<=a[fx][fy])
            continue;
        dp[fx][fy]=max(dp[fx][fy],dfs(x,y)+a[fx][fy]);
    }
    //printf("%d %d %d\n",fx,fy,dp[fx][fy]);
    return dp[fx][fy];
}
int main ()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(n==-1)
            break;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        memset(dp,0,sizeof(dp));
        printf("%d\n",dfs(0,0));
    }
    return 0;
}
