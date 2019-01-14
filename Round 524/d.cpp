#include<bits/stdc++.h>
#define ll long long
using namespace std;
double ksm(double a,ll k)
{
    double ans=1;
    while(k>0)
    {
        if(k%2==1)
            ans=ans*a;
        a=a*a;
        k/=2;
    }
    return ans;
}

ll br(ll len)
{
    if(len==0)
    return 0;
    ll ans=1;
    for(int i=1;i<=len-1;i++)
    {
        ans=ans*4+1;
    }
    return ans;
}

int main ()
{
    double ss;
    for(double i=1;i<=100;i++)
    {
        ss=log((i-1/3.0)*0.75)/log(4);
        //printf("%.0f %.10f\n",i,ss);
       // printf("YES %d %.10f\n",int(ss/log(2)),ss/log(2));
    }
    ll t;
    cin>>t;
    ll change,tmp;
    for(ll i=1;i<=t;i++)
    {
        ll n,k;
        scanf("%lld%lld",&n,&k);
        if(n>31)
        {
            printf("YES %lld\n",(n-1));
            continue;
        }
        ll sn=1;
        ll j=0,re=0;
        ll tot=0;
        while(sn+tot<=k && j<n)
        {
            tot+=sn;
            sn=sn*2+1;
            j++;
            re+=br(n-j)*(sn-2);
        }
        if(k>tot+re)
            printf("NO\n");
        else
            printf("yes %lld\n",n-j);
    }
    return 0;
}
