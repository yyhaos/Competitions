#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <cstdio>
using namespace std;
struct blk
{
    int x,y,h;
}b[205];
int n;
int dp[205][205],tem[5];
int main ()
{
    int cnt=1;
    while(~scanf("%d",&n))
    {
        //printf("n=%d\n",n);
        int tx,ty,th;
        if(n==0)
            break;
        n*=6;
        for(int i=0;i<n;i+=6)
        {
           // printf("%d\n",i);
            scanf("%d%d%d",&tem[0],&tem[1],&tem[2]);
            //printf("%d%d%d",tem[0],tem[1],tem[2]);
            int cn=0;
            for(int ii=0;ii<=2;ii++)
            {
                for(int j=0;j<=2;j++)
                {
                    for(int k=0;k<=2;k++)
                    {
                        if(ii==j||j==k||ii==k)
                        {
                            continue;
                        }
                        b[i+cn].x=tem[ii];
                        b[i+cn].y=tem[j];
                        b[i+cn++].h=tem[k];
                    }
                }
            }
        }
        memset(dp,0,sizeof(dp));
      //  printf("--\n");
        int ans=-1;
        for(int floor=1;floor<=n;floor++)
        {
      //      printf("%d\n",floor);
            for(int th=0;th<n;th++)
            {
                if(floor==1)
                {
                    dp[floor][th]=b[th].h;
                }
                else
                {
                    for(int k=0;k<n;k++)
                    {
                        if(b[k].x<b[th].x && b[k].y<b[th].y)
                            dp[floor][th]=max(dp[floor-1][k],dp[floor][th]);
                    }
                    dp[floor][th]+=b[th].h;
                }
                ans=max(ans,dp[floor][th]);
            }
        }
        printf("Case %d: maximum height = %d\n",cnt++,ans);
    }
    return 0;
}
