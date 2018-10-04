
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=50;
ll aa[maxn];
ll fa[maxn*1000+5];
ll bb[maxn];
ll fb[maxn*1000+5];
ll ma[1005];
void factor(ll n,ll a[maxn],ll b[maxn],ll &tot)
{
    ll temp,i,now;
    temp=(ll)((double)sqrt(n)+1);
    tot=0;
    now=n;
    for(ll i=2;i<=temp;i++)if(now%i==0)
    {
        a[++tot]=i;
        b[tot]=0;
        while(now%i==0)
        {
            ++b[tot];
            now/=i;
        }
    }
    if(now!=1)
    {
        a[++tot]=now;
        b[tot]=1;
    }
}



int main ()
{
    ll b,n,tv,tot=0,tt;
    scanf("%lld%lld",&b,&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&tv);
        factor(tv,aa,bb,tt);
        printf("tv = %lld %lld\n",tv,tt);
        for(int i=0;i<tt;i++)
        {
            printf("%lld %lld\n",aa[i] ,bb[i]);
        }
        for(int i=0;i<tt;i++)
        {
            int has=0;
            for(int j=0;j<tot;j++)
            {
                if(fa[j]==aa[i])
                {
                    has=1;
                    fb[j]+=bb[i];
                }
            }
            if(has==0)
            {
                fa[++tot]=aa[i];
                fb[tot]=bb[i];
            }

        }
    }
    printf("tot=%lld\n",tot);
    for(int i=0;i<tot;i++)
    {
        printf("%lld %lld\n",fa[i],fb[i]);
    }

    return 0;
}
