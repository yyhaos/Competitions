#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
unsigned int  n,m,X,Y,Z;
unsigned int R(void)
{
    X=X^(X<<11);
    X=X^(X>>4);
    X=X^(X<<5);
    X=X^(X>>14);
    unsigned int W=X^(Y^Z);
    X=Y;
    Y=Z;
    Z=W;
    return Z;
}
ull a[100005];
ull f[100005];
ull l[100005];
ull r[100005];
ull v[100005];
int main ()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%u%u%u%u%u",&n,&m,&X,&Y,&Z);
        for(int i=1;i<=3*m;i++)
        {
            f[i]=R();
        }
        for(int i=1;i<=m;i++)
        {
            l[i]=min(f[3*i-2]%n+1,f[3*i-1]%n+1);
            r[i]=max(f[3*i-2]%n+1,f[3*i-1]%n+1);
            v[i]=f[3*i]%(1<<30);
            //printf("%llu-%llu\n",l[i],r[i]);
            for(int j=l[i];j<=r[i];j++)
            {
                if(a[j]<v[i])
                    a[j]=v[i];
            }
        }
        ull ans=0;
        for(int i=1;i<=n;i++)
        {
            ans^=(i*a[i]);
        }
        printf("%llu\n",ans);
    }
    return 0;
}
