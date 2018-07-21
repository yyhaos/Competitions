#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+6;
const int mod = 1000000007;
//https://www.nowcoder.com/acm/contest/140#question

int q,k;

int main(){

    int n,m,ans;
    scanf("%d%d",&n,&m);
    if(n%2==1)
        ans=2*n-1;
    else
        ans=2*n;
    int usedx[n+5],usedy[n+5];
    memset(usedx,0,sizeof(usedx));
    memset(usedy,0,sizeof(usedy));
    int temy,temx;
    while(m--)
    {
        scanf("%d%d",&temx,&temy);
        usedx[temx]=1;
        usedy[temy]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(usedx[i]==1)
            ans--;
        if(usedy[i]==1)
            ans--;
        if(usedx[i]==1 && i==n/2+1 && n%2==1)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
