#include<bits/stdc++.h>
using namespace std;
double dp[405][405];
int main ()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=400;i++)
    {
        for(int j=1;j<=400;j++)
        {
            if(i>=j)
            {
                dp[i][j]=1.0*j/2.0;
            }
            else if(i==1)
            {
                dp[i][j]=0.5;
            }
            //else if(j==i+1)
           // {
           //     dp[i][j]=0.5*i+0.5*dp[i-1][j-1];
          //  }
            else
            {
                dp[i][j]=0.5*(1.0+dp[i-1][j-1])+0.5*dp[i][j-1];
            }
        }
    }
    printf("%.8lf",dp[n][k]);
    return 0;
}
