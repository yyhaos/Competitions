#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main ()
{
    int t;

    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        memset(a,0,sizeof(a));
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int ta,tb,tc;
        while(k--)
        {
            scanf("%d%d%d",&ta,&tb,&tc);
        if(a[tb]<tc)
            a[tb]=tc;
        }
        long long ans=0;
        for(int j=1;j<=m;j++)
            ans+=a[j];
        printf("Case #%d: %lld\n",ii,ans);
    }
    return 0;
}
