#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL q=1000000007LL;
LL ksm(LL a,LL t)
{
    if(t==0LL)
        return 1LL;
    LL ans=1LL;
    if(t%2LL==1LL)
        ans=(ans*a)%q;
    a=(a*a)%q;
    t/=2LL;
    ans=(ans*ksm(a,t))%q;
    return ans;
}
int main ()
{
    LL n;
    scanf("%lld",&n);
    LL ans1=(n*n)%q*n%q*n%q;
    LL ans2=((n*n)%q*(n)%q)%q;
    LL ans3=(n*n)%q;
    LL ans4=(n)%q;
    LL ans=0LL;
   // ans=(ans*(n-4))%q;
    ans=((ans1-(6LL*ans2)%q+2*q)%q+q)%q;
    ans=(ans+23LL*ans3)%q;
    ans=((ans-(42LL*ans4)%q+2*q)%q+q)%q;
  //  printf("%lld\n",ksm(3,3));
    LL ni=ksm(24,q-2);
    ans=ans*ni %q;
    if(n==3LL)
        ans=0LL;
    printf("%lld",(ans+1LL)%q);
    return 0;
}
