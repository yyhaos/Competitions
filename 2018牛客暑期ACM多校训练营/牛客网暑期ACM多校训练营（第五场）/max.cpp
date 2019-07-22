#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{

    return b==0?a:gcd(b,a%b);
}
int main ()
{
//printf("%lld\n",gcd(3,4));
    long long c,n;
    scanf("%lld%lld",&c,&n);
    long long a=0,b=0;

    for(long long i=n/c;i>=1;i--)
    {
            if(a<=0)
                a=i;
            else if(b<=0)
            {
                b=i;
            }

    }
    if(c==n)
        a=b=1;
    if(c<=n && b==0)
    {
        a=b=1;
    }
    if(b>0)
        printf("%lld\n",a*b*c*c);
    else
        printf("%lld\n",-1LL);
    return 0;
}
