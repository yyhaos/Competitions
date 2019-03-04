#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <cstdio>
using namespace std;
int dp[25][805];
int path[25][805];
int p1[205];
int v[205];
int s[205];
int p2[205];

int main ()
{
    int n , m, ii=0;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&p1[i],&p2[i]);
            s[i]=p1[i]+p2[i];
            v[i]=p1[i]-p2[i];
        }
        memset(path,-1,sizeof(path));
        memset(dp,-1,sizeof(dp));
        dp[0][400]=0;

        for(int j=0;j<m;j++)    // j!=m path 会变！！！！！！！！！
        {
            for(int c=0;c<=800;c++)
            {
                if(dp[j][c]!=-1)
                for(int i=1;i<=n;i++)
                {
                    if(dp[j][c]+s[i]>dp[j+1][c+v[i]])
                    {
                        int tj=j,tc=c;
                        while(tj!=0 && path[tj][tc]!=i)
                        {
                            tc-=v[path[tj][tc]];
                            tj--;
                        }
                        if(tj==0)   //非重复
                        {
                            dp[j+1][c+v[i]]=dp[j][c]+s[i];
                            path[j+1][c+v[i]]=i;
                        }
                    }
                }
                //if(dp[j][k]>=0)
                    //printf("%d %d %d\n",j,k,dp[j][k]);
            }
        }
        //int ans=-1;
        int k=0;
        while(dp[m][400+k]==-1 && dp[m][400-k]==-1)
            k++;
        if(dp[m][400+k]>dp[m][400-k])
            k=400+k;
        else k=400-k;
        //printf("k=%d\n",k);
        printf("Jury #%d\n",++ii);
        printf("Best jury has value %d for prosecution and value %d for defence:\n",
        (dp[m][k]+k-400)/2,(dp[m][k]-k+400)/2);
        int a[25];
        for(int t=m;t>=1;t--)
        {
            a[m-t]=path[t][k];
            k=k-v[path[t][k]];
        }
        sort(a,a+m);
        for(int i=0;i<m;i++)
            printf(" %d",a[i]);
        printf("\n\n");
    }
    return 0;
}
