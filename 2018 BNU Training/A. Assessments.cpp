
#include<bits/stdc++.h>
using namespace std;
int n,a1,a2,k;
double p;
double kk;
double dp[55][55][3005];
double dp2[55][3005];

int main ()
{
    freopen("assessment.in","r",stdin);
    int t;
    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        memset(dp,0.0,sizeof(dp));
        memset(dp2,0.0,sizeof(dp2));
        double ans=0.0;
        scanf("%d%lf%d%d%d",&n,&p,&a1,&a2,&k);
        if(n==1)
        {
            printf("Case %d: 1.00000\n",ii);
            continue;
        }
        dp2[a1][0]=1.0;
        dp[a2][a1][0]=1.0;
        kk=1.0/(n-1.0);
        //printf("%lf %d\n",kk,n);
        if(a1==a2)
        {
            for(int th=0;th<k;th++)
            {
               // printf("th=%d: ",th);
                for(int i=0;i<n;i++)
                {
                    double ps = kk*p*dp2[i][th];
					double res = dp2[i][th];
					if (i>0)
                    {
						dp2[i - 1][th+1] += ps;
						res-= ps;
					}
					if (i <n - 1)
                    {
						dp2[i + 1][th + 1] += ps;
						res -= ps;
					}
					dp2[i][th+1] += res;
                //    printf("%lf\t",dp2[i][th]);
                }
             //   printf("\n");
            }
           // printf("\n");
            ans=dp2[a1][k];
            printf("Case %d: %.5lf\n",ii,ans);
            continue;
        }

        for(int th=0;th<k;th++)
        {
            //printf("th=%d %d %d ",th,n,n);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                  //  printf("(%d %d) ",i,j);
                    double ps=kk*p*dp[i][j][th];
                    double re=dp[i][j][th];
                    if (i>0)
                    {
                        if (j+1==i)
                        {
                            dp[j][i][th+1] += ps;
                            re -= ps;
                        }
                        else
                        {
                            dp[i-1][j][th+1]+=ps;
                            re -= ps;
                        }
                    }
                    if (i != n - 1)
                    {
                        if (i + 1 == j)
                        {
                            dp[j][i][th+1] += ps;
                            re -= ps;
                        }
                        else
                        {
                            dp[i+1][j][th+1] += ps;
                            re -= ps;
                        }
                    }
                    if (j>0)
                    {
                        if (i + 1 != j)
                        {
                            dp[i][j-1][th+1] += ps;
                            re -= ps;
                        }
                    }
                    if (j != n - 1)
                    {
                        if (j + 1 != i)
                        {
                            dp[i][j+1][th+1] += ps;
                            re -= ps;
                        }
                    }
                    dp[i][j][th+1] += re;
                  //  printf("%lf\t",dp[i][j][th]);
                }
            //    printf("\n");
            }
          //  printf("\n");
        }
        ans=dp[a1][a2][k];
        printf("Case %d: %.5lf\n",ii,ans);
    }
    return 0;
}
