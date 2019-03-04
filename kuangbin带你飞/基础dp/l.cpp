#include<stdio.h>
#include<iostream>
#include <cstring>
#include <cstdio>
#include<algorithm>
using namespace std;
int dp[500][500];
int main ()
{
    string x,y;
    while(cin>>x>>y)
    {
        memset(dp,0,sizeof(dp));
        if(x.length()<=0)
            break;
        int m=x.length(),n=y.length();
        for(int i=0;i<m;i++)
            dp[i][0]=0;
        for(int i=0;i<n;i++)
            dp[0][i]=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(x[i]==y[j])
                    dp[i+1][j+1]=dp[i][j]+1;
                else if(dp[i][j+1]>=dp[i+1][j])
                    dp[i+1][j+1]=dp[i][j+1];
                else
                    dp[i+1][j+1]=dp[i+1][j];
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
