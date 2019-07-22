#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
char s[MAXN];
int dp[MAXN][2];
int a[MAXN][2];
int main(void)
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++){
        a[i][0]=s[i]-'0';
        a[i][1]='9'-s[i];
    }
    dp[0][0]=a[0][0];dp[0][1]=a[0][1]+2;
    for(int i=1;i<n;i++){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1])+a[i][0];
        dp[i][1]=min(dp[i-1][1]+a[i][1],dp[i-1][0]+a[i][1]+2);
    }
//    for(int i=0;i<n;i++)
//    {
//        printf("%d %d %d\n",i,dp[i-1][1],dp[i][1]);
//    }
    printf("%d\n",min(dp[n-1][0],dp[n-1][1]));
}
