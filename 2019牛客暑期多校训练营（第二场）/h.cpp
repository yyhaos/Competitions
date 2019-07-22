
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10;
int n,m;
char s[MAXN][MAXN];
int dp[MAXN][MAXN];
int h[MAXN][MAXN];
int w[MAXN][MAXN];
int ans1,ans2;
int main()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
//        printf("%s\n",s[i]+1);
        getchar();
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='1')
            {
                h[i][j]=min(w[i][j-1]+1,h[i][j-1]+1);
                w[i][j]=min(h[i-1][j]+1,w[i-1][j]+1);
                dp[i][j]=h[i][j]*w[i][j];
//                printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
            }
            if(dp[i][j]>=ans1)
            {
                ans2=ans1;
                ans1=dp[i][j];
            }
            else if(dp[i][j]>ans2)ans2=dp[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<h[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    printf("%d",ans2);
    return 0;
}
