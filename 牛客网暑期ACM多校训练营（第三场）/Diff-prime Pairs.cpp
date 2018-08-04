#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 10000007;
int vis[maxn];
long long dp[maxn][2];

void C()
{
    dp[2][2] = 1;
    dp[2][1] = 2;
    dp[1][1] = 1;
    for(long long i = 3;i<maxn;i++)
    {
        dp[i][1] = i;
        dp[i][2] = dp[i-1][1]+dp[i-1][2];
    }
}

long long pr(long long N)
{
    memset(vis,0,sizeof(vis));
    long long sum = 0;
    long long ans=0;
    for(long long i = 2;i<=N;i++)
    {
        if(!vis[i])
        {
            for(long long j = 2*i;j<=N;j+=i)
                vis[j] = 1;
        }
    }
    for(long long i = 2;i<=N;i++)
        if(!vis[i])
        {
            sum++;
            ans+=N/i*(sum-1)*2;
        }
    return ans;
}

int main()
{
    //C();
    long long N;
    scanf("%lld",&N);
    long long k = pr(N);
    cout<<k<<endl;
    return 0;
}
