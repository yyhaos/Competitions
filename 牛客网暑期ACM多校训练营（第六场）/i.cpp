#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct ship
{
    LL l, r;
}s[200005];
LL y[200005];
LL fb[200005];
int main ()
{
    int t;

    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        memset(fb,0,sizeof(fb));
        memset(y,0,sizeof(y));
        memset(s,0,sizeof(s));
       // int ans=0;
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&s[i].l,&s[i].r);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%lld",&y[i]);
        }

        printf("Case #%d:\n",ii);
        LL res=0;
        int th=0,cnt=0;
        for(int i=0;i<m;i++)
        {
            if(cnt>=n)
            {
                printf("0\n");
                continue;
            }
            LL xi=(y[i] ^ (res%998244353LL));
           // printf("xi=%d %lld %lld\n",xi,y[i],res);
            res=0;
            th=0;
            for(int j=0;j<n;j++)
            {
                if(s[j].l<=xi && s[j].r>=xi)
                {
                    if(res==0LL)
                        res=1LL;
                    res=((1LL+j)*res)%998244353LL;
                    if(fb[j]==0)
                    {
                        th++;
                        fb[j]=i+1LL;
                    }
                }
            }
           // cnt+=th;
            printf("%d\n",th);
        }
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                printf(" ");
            printf("%lld",fb[i]);
        }
        printf("\n");
    }
    return 0;
}
