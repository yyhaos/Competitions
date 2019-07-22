#include<bits/stdc++.h>
using namespace std;
long long C[2050][2055];
long long q=1e9+7;
//Problems  :   https://www.nowcoder.com/acm/contest/139#question

int main ()
{
    int n,m;
    int N=2005;
    C[1][1]=1LL;
    memset(C,0LL,sizeof(C));
    C[1][0] = C[1][1] = 1LL;
    for (int i = 2; i < N; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j < N; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1])%q;
    }
    while(~scanf("%d%d",&n,&m))
    {
        printf("%lld\n",((C[n+m][n]*C[n+m][n])%q-(C[m+n][m-1]*C[n+m][n-1])%q+q)%q);
    }
    return 0;
}
