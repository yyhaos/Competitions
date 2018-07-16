#include<bits/stdc++.h>
using namespace std;
#define LL long long

const long long m1=1000LL;
const long long m2=5001LL;
LL k[m1+5][m2+5];

const LL q=1e9+7LL;
LL C(LL c1,LL c2)
{
    LL CC(LL d,LL  s);
    LL d=c2-c1;
    LL p=c1/3LL;
    LL s=d+p;

   // printf("ds=%lld %lld\n",d,s);
    LL ans=1LL;
    for(LL i=d+1;i<d+1+p;i++)
    {
        ans=(ans*i)%q;
    }
    return ans;
}
LL CC(LL d,LL s)
{
    if(s-d<d)
        d=s-d;
    if(d==0LL)
        return 1LL;
    if(d==1LL)
        return s;
    if(d==s)
        return 1LL;
    if(s==1LL)
        return 1LL;
    LL ans=1LL;
    if(d<=m1 && s<=m2)
    {
        if(k[d][s]>0LL)
        {
            return k[d][s];
        }
        ans=(CC(d-1LL,s-1LL)+CC(d,s-1LL))%q;
        k[d][s]=ans;
        return ans;
    }
    ans=(CC(d-1LL,s-1LL)+CC(d,s-1LL))%q;
    return ans;

}
LL A(LL n)
{
    LL ans=1LL;
    for(LL i=1LL;i<=n;i++)
    {
        ans=(ans*i)%q;
    }
    return ans;
}
int main ()
{
    memset(k,0LL,sizeof(k));

    LL c,n;

    //CC(m1,m2);

    scanf("%lld %lld",&n,&c);
    LL ans=1LL;
    for(LL i=1;i<=n;i++)
    {
        ans=(ans*6LL)%q;
    }
    LL ned_c=3LL*n;
   // printf("C=%lld A=%lld xx%lld\n",C(ned_c,c),A(n),ans);
    ans=(ans*C(ned_c,c))%q;
    printf("%lld",ans);
    return 0;
}
