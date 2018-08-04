#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    short N;
    cin>>N;
    short p[N+1],a[N+1],c[N+1],m[N+1],g[N+1];
    for(int i = 0;i<N;i++)
        scanf("%d%d%d%d%d",&p[i],&a[i],&c[i],&m[i],&g[i]);
    short P,A,C,M;
    cin>>P>>A>>C>>M;
    short dp[P+1][A+1][C+1][M+1];
    memset(dp,0,sizeof(dp));
    short i,j,k,x,y;
    for(i = 0;i<N;i++)
    {
        for(j = P;j>=p[i];j--)
        {
            for(k = A;k>=a[i];k--)
            {
                for(x = C;x>=c[i];x--)
                {
                    for(y = M;y>=m[i];y--)
                    {
                        if(dp[j-p[i]][k-a[i]][x-c[i]][y-m[i]]+g[i] > dp[j][k][x][y])
                        {
                            dp[j][k][x][y] = dp[j-p[i]][k-a[i]][x-c[i]][y-m[i]]+g[i];
                        }
                    }
                }
            }
        }
    }
    short ans = 0;
    short s[37];
    for(i = N-1;i>=0;i--)
    {
        if(P>=p[i] && A>=a[i] && C>=c[i] && M>=m[i])
        {
            if(dp[P][A][C][M] - g[i] == dp[P-p[i]][A-a[i]][C-c[i]][M-m[i]])
            {
                s[ans++] = i;
                P-=p[i];A-=a[i];C-=c[i];M-=m[i];
            }
        }
    }
    printf("%d\n",ans);
    for(i = 0;i<ans;i++)
    {
        printf("%d",s[ans-i-1]);
        if(i != ans-1)
            printf(" ");
    }
    return 0;
}
